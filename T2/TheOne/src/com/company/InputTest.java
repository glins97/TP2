package com.company;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static org.junit.Assert.*;

public class InputTest {

    @Test
<<<<<<< HEAD
    public void loadWords() {
        List<String> words = new Input().loadWords("names");
        List<String> check = Arrays.asList("gabriel", "gabriel", "gabriel", "gabriel", "matheus",
                "romullo", "rafael", "joão", "joão", "julia", "raquel", "raquel", "raquel", "julia");

        assert words.equals(check);
    }

    @Test
    public void filterWords() {
        List<String> words = new ArrayList(Arrays.asList("a", " a", "!a", "$a", "(a)", "a.", "a'", "$!@#$%"));
        words = new Input().filterWords(words);
        List<String> check = Arrays.asList("a", "a", "a", "a", "a", "a", "a", "");
=======
    public void filterWords() {
        // Check for special chars before and after words
        List<String> words = new ArrayList<String>(Arrays.asList("a", " a", "!a", "$a", "(a)", "a.", "a'", "$!@#$%"));
        words = new Input().filterWords(words);
        List<String> check = Arrays.asList("a", "a", "a", "a", "a", "a", "a", "");

        // For each item, check if it's the expected value
>>>>>>> ef92326c45ce3bfe7544881d7ce3ffa5ced984ec
        for (int i=0; i < words.size(); i++){
            assert words.get(i).equals(check.get(i));
        }
    }

    @Test
    public void normalizeWords() {
<<<<<<< HEAD
        List<String> words = Arrays.asList("AaA", "a", "", "A", "AA");
        words = new Input().normalizeWords(words);
        List<String> check = Arrays.asList("aaa", "a", "", "a", "aa");
=======
        // Check if words are normalized
        List<String> words = Arrays.asList("AaA", "a", "", "A", "AA");
        words = new Input().normalizeWords(words);
        List<String> check = Arrays.asList("aaa", "a", "", "a", "aa");

        // For each item, check if it's the expected value
>>>>>>> ef92326c45ce3bfe7544881d7ce3ffa5ced984ec
        for (int i=0; i < words.size(); i++){
            assert words.get(i).equals(check.get(i));
        }
    }

    @Test
    public void removeStopWords() {
<<<<<<< HEAD
        List<String> words = new ArrayList(Arrays.asList("a", "b", "c", "d", "e"));
        List<String> stopWords = Arrays.asList("c", "d");
        words = new Input().removeStopWords(words, stopWords);
        List<String> check = Arrays.asList("a", "b", "e");
=======
        // Removes stop words
        List<String> words = new ArrayList<String>(Arrays.asList("a", "b", "c", "d", "e"));
        List<String> stopWords = Arrays.asList("c", "d");
        words = new Input().removeStopWords(words, stopWords);
        List<String> check = Arrays.asList("a", "b", "e");

        // For each item, check if it's the expected value
>>>>>>> ef92326c45ce3bfe7544881d7ce3ffa5ced984ec
        for (int i=0; i < words.size(); i++){
            assert words.get(i).equals(check.get(i));
        }
    }
<<<<<<< HEAD
=======

    @Test
    public void loadWords() {
        List<String> words = new Input().loadWords("names");
        List<String> check = Arrays.asList("gabriel", "gabriel", "gabriel", "gabriel", "matheus",
                "romullo", "rafael", "joão", "joão", "julia", "raquel", "raquel", "raquel", "julia");

        assert words.equals(check);
    }

>>>>>>> ef92326c45ce3bfe7544881d7ce3ffa5ced984ec
}