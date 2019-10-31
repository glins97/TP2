package com.company;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.stream.Collectors;

public class Output {

    public Output(){}

    public LinkedHashMap sortMapByValues(Map<String, Integer> map){
        assert map.keySet().size() != 0: "Map has no keys! Did you load it?";

        return  map.entrySet().stream()
                    .sorted(Map.Entry.<String, Integer>comparingByValue().reversed())
                        .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue,
                                (e1, e2) -> e1, LinkedHashMap::new));
    }

    public String getIndentation(String word, Integer maxLevel){
        assert word.length() != 0: "Can't calculate indent level of an empty word!";
        assert maxLevel >= 0: "Max level can't be negative!";
        String r = "";
        for (int i = 0; i < maxLevel - (word.length() / 8); i++){
            r = r + "\t";
        }
        return r;
    }

    public Object printMap(Map<String, Integer> map, Integer maxRank){
        assert map.keySet().size() != 0: "Map has no keys! Can't print!";

        int index = 0;
        int tabSize = 1;
        int keyMaxSize = 0;
        for (String key: map.keySet()){
            if (key.length() > keyMaxSize){
                keyMaxSize = key.length();
                tabSize = keyMaxSize / 8 - 1;
            }
        }

        String maxIndent = "";
        for (int i = 0; i< tabSize; i++){
            maxIndent = maxIndent + "\t";
        }

        System.out.println("Rank\tWord" + maxIndent + "Count");
        for (String key: map.keySet()){
            if (index++ >= maxRank && maxRank > 0) break;
            System.out.println(index + "\t" + key + getIndentation(key, tabSize) + map.get(key));
        }
        return map;
    }

    public Object saveMap(Map<String, Integer> map, String filename){
        assert map.keySet().size() != 0: "Map has no keys! Can't save!";
        assert filename.length() != 0: "Output filename must have at least one letter!";

        int index = 0;
        try{
            FileWriter file = new FileWriter("../resources/output/" + filename);
            BufferedWriter writer = new BufferedWriter(file);
            writer.write("Rank,Word,Count\n");
            for (String key: map.keySet()){
                writer.write(++index + "," + key + "," + map.get(key) + "\n");
            }
            writer.close();
        }
        catch (IOException e) {
            e.printStackTrace();
        }

        return  map;
    }
}
