package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Input {

    public Input(){}

    public List<String> streamKeyboardInputs(){
        System.out.println("Enter desired words: ");

        List<String> inputs = new ArrayList<String>();
        Scanner scanner = new Scanner(System.in);
        String line = scanner.nextLine();
        while (!line.toLowerCase().equals("$done")){
            inputs.add(line);
            line = scanner.nextLine();
        }
        return inputs;
    }

    public List<String> loadWords(String filename){
        List<String> words = new ArrayList<String>();
        File file = new File("/home/glins/Documents/UnB/Matérias/TP2/T2/resources/input/" + filename);
        Scanner sc = null;
        try {
            sc = new Scanner(file);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        String[] line;
        while (sc.hasNextLine()){
            line = sc.nextLine().split(" ");
            for (String word: line){
                if (word.length() > 0)
                    words.add(word);
            }
        }

        return words;
    }

    public List<String> filterWords(Object words_){
        List<String> words = (List<String>) words_;
        Pattern pattern = Pattern.compile("([a-zA-Z]+)");

        int index = 0;
        for (String word: new ArrayList<>(words)){

            Matcher matcher = pattern.matcher(word);
            if (matcher.find())
                words.set(index++, matcher.group(1));
            else words.remove(index);
        }

        return words;
    }

    public List<String> normalizeWords(Object words_){
        List<String> words = (List<String>) words_;
        int index = 0;
        for (String word: words){
            words.set(index++, word.toLowerCase());
        }

        return words;
    }

    public List<String> removeStopWords(Object words_, List<String> stopWords){
        List<String> words = (List<String>) words_;
        int index = 0;
        for (String word: new ArrayList<>(words)){
            if (stopWords.contains(word)){
                words.remove(index);
            }
            else index++;
        }

        return words;
    }

}
