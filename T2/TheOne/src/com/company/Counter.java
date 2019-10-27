package com.company;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Counter {

    public Map<String, Integer> getFrequencyList(Object words){
        Map<String, Integer> frequencyList = new HashMap<String, Integer>();
        for (String word: (List<String>) words){
            Integer currentWordFrequency = frequencyList.getOrDefault(word, 0);
            frequencyList.put(word, currentWordFrequency + 1);
        }
        return frequencyList;
    }

}
