package com.company;

import org.junit.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.Assert.*;

public class CounterTest {

    @Test
    public void getFrequencyList() {
        Counter counter = new Counter();

        // Empty words test
        List<String> words2 = Collections.emptyList();
        assert counter.getFrequencyList(words2).keySet().size() == 0;

        // Case test
        List<String> words = Arrays.asList("Gabriel", "Gabriel", "Matheus", "", "", "gabriel");
        assert counter.getFrequencyList(words).get("Gabriel") == 2;
        assert counter.getFrequencyList(words).get("Matheus") == 1;
        assert counter.getFrequencyList(words).get("") == 2;
        assert counter.getFrequencyList(words).get("gabriel") == 1;

    }
}