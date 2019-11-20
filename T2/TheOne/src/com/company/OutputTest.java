package com.company;

import org.junit.Test;

import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

import static org.junit.Assert.*;

public class OutputTest {

    @Test
    public void sortMapByValues() {
        // Will test using 'dracula' file
        List<String> words = new Input().loadWords("dracula");
        Map<String, Integer> map = new Counter().getFrequencyList(words);

        // Sorts obtained frequency list
        LinkedHashMap<String, Integer> map_ = new Output().sortMapByValues(map);

        // Asserts if, after sorting, each value is lower or equal to last value
        Integer count = map_.get(map_.keySet().toArray()[0]);
        for (Object key: map_.keySet()){
            assert map.get(key) <= count;
            count = map.get(key);
        }
    }
}