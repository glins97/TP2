package com.company;

import java.util.Arrays;
import java.util.List;

interface I {
    Object run(Object o);
}

public class Main {
    private Counter counter;
    private Display display;
    private Input input;
    private Output output;
    public Object result;

    public Main(){
        this.input = new Input();
        this.output = new Output();
        this.display = new Display();
        this.counter = new Counter();
    }

    public Main bind(I method){
        this.result = method.run(this.result);
        return this;
    }

    public static void main(String[] args) {
        Main main = new Main();
        String inputFilename = main.display.requestInput("Enter input filename: ");
        String outputFilename = main.display.requestInput("Enter output filename: ");
        List<String> stopWords = Arrays.asList("the", "and", "i", "to", "of", "a");

        main.bind(p -> main.input.loadWords(inputFilename))
                .bind(p -> main.input.normalizeWords(p))
                .bind(p -> main.input.filterWords(p))
                .bind(p -> main.input.removeStopWords(p, stopWords))
                .bind(p -> main.counter.getFrequencyList(p))
                .bind(p -> main.output.sortMapByValues(p))
                .bind(p -> main.output.saveMap(p, outputFilename))
                .bind(p -> main.output.printMap(p, 0));
    }
}
