package com.company;

import java.util.*;

public class Main {
    private Counter counter;
    private Input input;
    private Output output;
    private String inputFilename;
    private String outputFilename;
    private List<String> stopWords;

    public Main(){
        this.input = new Input();
        this.output = new Output();
        this.counter = new Counter();
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
            choice = Integer.valueOf(requestInput("Enter a choice: "));
            if (choice < 1 || choice > messages.size()){
                System.out.println("Choice not available, try again.");
            }
        }
        return choice;
    }

    public void requestConfigs(){
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
    }

    public static void main(String[] args) {
        Main main = new Main();
        Boolean done = false;
        while (!done){
            try{
                done = true;
                main.requestConfigs();
                List<String> words = main.input.loadWords(main.inputFilename);
                words = main.input.normalizeWords(words);
                words = main.input.filterWords(words);
                words = main.input.removeStopWords(words, main.stopWords);

                Map<String, Integer> map = main.counter.getFrequencyList(words);
                map = main.output.sortMapByValues(map);
                main.output.saveMap(map, main.outputFilename);
                main.output.printMap(map, 15);
            }
            catch (AssertionError e) {
                System.out.println("\n[ASSERT ERROR] Something went wrong! -> '" + e.getMessage() + "'");
                if (main.requestInput("Enter 'yes' to try again: ").equals("yes")) done = false;
            }
        }


    }
}
