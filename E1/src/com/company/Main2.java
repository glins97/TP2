package com.company;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.nio.charset.Charset;
import java.nio.charset.CharsetDecoder;
import java.nio.charset.StandardCharsets;
import java.security.Provider;
import java.security.Provider.Service;
import java.security.Security;
import java.util.Random;

import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;


public class Main2 {
    //
    // useful: https://stackoverflow.com/questions/15554296/initial-bytes-incorrect-after-java-aes-cbc-decryption
    //
    public static void main(String args[]) {
        if(args.length < 1) {
            help();
        }
        try {
            switch(args[0]) {
                case "--list": list(args); break;
                case "--generate-key": generateKey(args);
                case "--generate-password": generatePassword(args); break;
                case "--retrieve-password": retrievePassword(args); break;
            }
        }
        catch(Exception e) {
            e.printStackTrace();
        }
    }


    // https://stackoverflow.com/questions/304268/getting-a-files-md5-checksum-in-java
    // @Bill_The_Lizzard
    private static String bytesToHex(byte[] bytes) {
        String result = "";
        for (byte b: bytes) {
            result += Integer.toString((b & 0xff) + 0x100, 16).substring(1);
        }
        return result;
    }

    // https://stackoverflow.com/questions/140131/convert-a-string-representation-of-a-hex-dump-to-a-byte-array-using-java
    public static byte[] hexToBytes(String s) {
        int len = s.length();
        byte[] data = new byte[len / 2];
        for (int i = 0; i < len; i += 2) {
            data[i / 2] = (byte) ((Character.digit(s.charAt(i), 16) << 4)
                    + Character.digit(s.charAt(i+1), 16));
        }
        return data;
    }

    private static void generateKey(String args[]) throws Exception {
        KeyGenerator kg = KeyGenerator.getInstance("AES");
        SecretKey key = kg.generateKey();
        ObjectOutputStream os = new ObjectOutputStream(new FileOutputStream(new File(args[1])));
        os.writeObject(key);
        os.flush();
        os.close();
    }
    private static void generatePassword(String args[]) throws Exception {
        byte[] password = new byte[16];
        new Random().nextBytes(password);

        ObjectInputStream ois = new ObjectInputStream(new FileInputStream(new File(args[1])));

        SecretKey key = (SecretKey)ois.readObject();

        Cipher cipher = Cipher.getInstance("AES/ECB/NoPadding");
        cipher.init(Cipher.ENCRYPT_MODE, key);
        byte[] res = cipher.doFinal(password);

        System.out.println("Plain text password " + bytesToHex(password));
        System.out.println("Ciphered password " + bytesToHex(res));

        ois.close();
    }

    private static void retrievePassword(String args[]) throws Exception {
        byte[] cipheredPassword = hexToBytes(args[1]);

        ObjectInputStream ois = new ObjectInputStream(new FileInputStream(new File(args[2])));
        SecretKey key = (SecretKey)ois.readObject();

        Cipher cipher = Cipher.getInstance("AES/ECB/NoPadding");
        cipher.init(Cipher.DECRYPT_MODE, key);

        byte[] res = cipher.doFinal(cipheredPassword);

        System.out.println("Ciphered password " + bytesToHex(cipheredPassword));
        System.out.println("Plain text password " + bytesToHex(res));
    }

    private static void list(String args[]) {
        if(args.length == 1) {
            Provider[] providers = Security.getProviders();
            for(Provider p: providers) {
                System.out.println(String.format("%s: %s", p.getName(), p.getInfo()));
            }
        }
        else if(args.length == 3) {
            String providerName = args[1];
            String primitiveName = args[2];

            Provider p = Security.getProvider(providerName);

            System.out.println("List of available algorithms for " + primitiveName);

            assert p != null;
            assert p.getServices() != null;

            for(Service service: p.getServices()) {
                if(service.getType().equals(primitiveName)) {
                    System.out.println(service.getAlgorithm());
                }
            }
        }
        else {
            help();
        }
    }

    private static void help() {
        System.out.println("Try the following commands");
        System.out.println(" --list    : list the name of the installed providers");
        System.out.println(" --list <provider> <algorithm>  : list the implementations of an algorithm from a given provider");
        System.exit(0);
    }

}
