package com.company;

import java.util.Arrays;
import java.util.List;
import java.util.Map;

public class Main {
    private Counter counter;
    private Display display;
    private Input input;
    private Output output;

    public Main(){
        this.input = new Input();
        this.output = new Output();
        this.display = new Display();
        this.counter = new Counter();
    }

    public static void main(String[] args) {
        Main main = new Main();
        String inputFilename = main.display.requestInput("Enter input filename: ");
        String outputFilename = main.display.requestInput("Enter output filename: ");
        List<String> stopWords = Arrays.asList("the", "and", "i", "to", "of", "a");

        List<String> words = main.input.loadWords(inputFilename);
        words = main.input.normalizeWords(words);
        words = main.input.filterWords(words);
        words = main.input.removeStopWords(words, stopWords);

        Map<String, Integer> map = main.counter.getFrequencyList(words);
        map = main.output.sortMapByValues(map);
        main.output.saveMap(map, outputFilename);
        main.output.printMap(map, 15);
    }
}
