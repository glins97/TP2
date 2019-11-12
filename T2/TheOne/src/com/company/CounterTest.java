package com.company;

import org.junit.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.Assert.*;

public class CounterTest {

    @Test
    public void getFrequencyList() {
        // Case test
        List<String> words = Arrays.asList("Gabriel", "Gabriel", "Matheus", "");
        assert new Counter().getFrequencyList(words).get("Gabriel") == 2;
        assert new Counter().getFrequencyList(words).get("Matheus") == 1;
        assert new Counter().getFrequencyList(words).get("") == 1;

        // Empty words test
        List<String> words2 = Arrays.asList();
        assert new Counter().getFrequencyList(words2).keySet().size() == 0;
    }
}