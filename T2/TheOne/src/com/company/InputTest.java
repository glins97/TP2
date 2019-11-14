package com.company;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static org.junit.Assert.*;

public class InputTest {

    @Test
    public void filterWords() {
        // Check for special chars before and after words
        List<String> words = new ArrayList<String>(Arrays.asList("a", " a", "!a", "$a", "(a)", "a.", "a'", "$!@#$%"));
        words = new Input().filterWords(words);
        List<String> check = Arrays.asList("a", "a", "a", "a", "a", "a", "a", "");

        // For each item, check if it's the expected value
        for (int i=0; i < words.size(); i++){
            assert words.get(i).equals(check.get(i));
        }
    }

    @Test
    public void normalizeWords() {
        // Check if words are normalized
        List<String> words = Arrays.asList("AaA", "a", "", "A", "AA");
        words = new Input().normalizeWords(words);
        List<String> check = Arrays.asList("aaa", "a", "", "a", "aa");

        // For each item, check if it's the expected value
        for (int i=0; i < words.size(); i++){
            assert words.get(i).equals(check.get(i));
        }
    }

    @Test
    public void removeStopWords() {
        // Removes stop words
        List<String> words = new ArrayList<String>(Arrays.asList("a", "b", "c", "d", "e"));
        List<String> stopWords = Arrays.asList("c", "d");
        words = new Input().removeStopWords(words, stopWords);
        List<String> check = Arrays.asList("a", "b", "e");

        // For each item, check if it's the expected value
        for (int i=0; i < words.size(); i++){
            assert words.get(i).equals(check.get(i));
        }
    }

    @Test
    public void loadWords() {
        List<String> words = new Input().loadWords("names");
        List<String> check = Arrays.asList("gabriel", "gabriel", "gabriel", "gabriel", "matheus",
                "romullo", "rafael", "joão", "joão", "julia", "raquel", "raquel", "raquel", "julia");

        assert words.equals(check);
    }

}