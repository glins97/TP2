package com.company ;

import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.security.MessageDigest;

public class Main {

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

    private static byte[] _getFileHash(String path){
        MessageDigest md = null;
        try {
            md = MessageDigest.getInstance("SHA-256");
            InputStream is = Files.newInputStream(Paths.get(path));
            return md.digest(is.readAllBytes());

        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }

    private static String hash(String[] args){
        byte[] bytes = _getFileHash(args[1]);
        return bytesToHex(bytes);
    }

    private static boolean verify(String[] args){
        String hash = hash(args);
        return hash.equals(args[2]);
    }

    public static void main(String[] args) {
        try{
            switch (args[0]){
                case "--hash":
                    System.out.println(hash(args)); break;
                case "--verify":
                    System.out.println(verify(args));break;
            }
        }
        catch(Exception e){
            e.printStackTrace();
        }

    }
}
