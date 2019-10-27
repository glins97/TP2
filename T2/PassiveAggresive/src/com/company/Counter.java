package com.company;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Counter {

    public Map<String, Integer> getFrequencyList(List<String> words){
        assert words.size() != 0: "Word list is empty! Can't filter!";

        Map<String, Integer> frequencyList = new HashMap<String, Integer>();
        for (String word: words){
            Integer currentWordFrequency = frequencyList.getOrDefault(word, 0);
            frequencyList.put(word, currentWordFrequency + 1);
        }
        return frequencyList;
    }

}
