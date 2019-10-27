package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Input {

    public Input(){}

    public List<String> loadWords(String filename){
        assert filename.length() != 0: "Filename should have at least a letter!";
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

    public List<String> filterWords(List<String> words){
        assert words.size() != 0: "Word list is empty! Can't filter!";

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

    public List<String> normalizeWords(List<String> words){
        assert words.size() != 0: "Word list is empty! Can't normalize!";

        int index = 0;
        for (String word: words){
            words.set(index++, word.toLowerCase());
        }

        return words;
    }

    public List<String> removeStopWords(List<String> words, List<String> stopWords){
        assert words.size() != 0: "Word list is empty! Can't remove stop words!";
        assert stopWords.size() != 0: "Stop words is empty!";

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
