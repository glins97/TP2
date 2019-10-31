package com.company;

import java.util.*;

interface I {
    Object run(Object o);
}

public class Main {
    private Counter counter;
    private Input input;
    private Output output;
    private String inputFilename;
    private String outputFilename;
    private List<String> stopWords;

    public Object result;

    public Main(){
        this.input = new Input();
        this.output = new Output();
        this.counter = new Counter();
    }

    public Main bind(I method){
        this.result = method.run(this.result);
        return this;
    }

    public String requestInput(String message){
        assert message.length() != 0: "Message must have at least one letter!";
        Scanner scanner = new Scanner(System.in);
        System.out.print(message);
        return scanner.nextLine();
    }

    public Integer requestChoice(String title, List<String> messages){
        Integer choice = 0;
        StringBuilder message = new StringBuilder(title + "\n");
        for (int i = 0; i < messages.size(); i++){
            int index = i + 1;
            message.append(String.format("\t%s. %s\n", Integer.toString(index), messages.get(i)));
        }

        System.out.print(message);
        while(choice < 1 || choice > messages.size()){
            try{
                choice = Integer.valueOf(requestInput("Enter a choice: "));
            }
            catch (NumberFormatException e){
                choice = 0;
            }
            if (choice < 1 || choice > messages.size()){
                System.out.println("Choice not available, try again.");
            }
        }
        return choice;
    }

    public Object requestConfigs(){
        this.inputFilename = this.requestInput("Enter input filename: ");
        this.outputFilename = this.requestInput("Enter output filename: ");
        Integer stopWordsLoadMethod = this.requestChoice("How do you wish to input stop words?",
                Arrays.asList("File", "Type", "Hardcoded", "No stopwords"));

        this.stopWords = new ArrayList<String>();
        switch (stopWordsLoadMethod){
            case 1: {
                this.stopWords = this.input.loadWords(this.requestInput("Enter stopwords filename: "));
                break;
            }
            case 2: {
                this.stopWords = this.input.streamKeyboardInputs();
                break;
            }
            case 3: {
                this.stopWords = Arrays.asList("the", "and", "i", "to", "of", "a");
                break;
            }
            case 4: break;
        }
        return this;
    }

    public static void main(String[] args) {
        Main main = new Main();
        main.bind(p -> main.requestConfigs())
                .bind(p -> main.input.loadWords(main.inputFilename))
                .bind(p -> main.input.normalizeWords(p))
                .bind(p -> main.input.filterWords(p))
                .bind(p -> main.input.removeStopWords(p, main.stopWords))
                .bind(p -> main.counter.getFrequencyList(p))
                .bind(p -> main.output.sortMapByValues(p))
                .bind(p -> main.output.saveMap(p, main.outputFilename))
                .bind(p -> main.output.printMap(p, 15));
    }
}
