package com.company;

import org.junit.Test;

import java.util.Arrays;
<<<<<<< HEAD
=======
import java.util.Collections;
>>>>>>> ef92326c45ce3bfe7544881d7ce3ffa5ced984ec
import java.util.List;

import static org.junit.Assert.*;

public class CounterTest {

    @Test
    public void getFrequencyList() {
<<<<<<< HEAD
        // Case test
        List<String> words = Arrays.asList("Gabriel", "Gabriel", "Matheus", "");
        assert new Counter().getFrequencyList(words).get("Gabriel") == 2;
        assert new Counter().getFrequencyList(words).get("Matheus") == 1;
        assert new Counter().getFrequencyList(words).get("") == 1;

        // Empty words test
        List<String> words2 = Arrays.asList();
        assert new Counter().getFrequencyList(words2).keySet().size() == 0;
=======
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

>>>>>>> ef92326c45ce3bfe7544881d7ce3ffa5ced984ec
    }
}