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

    public LinkedHashMap sortMapByValues(Object map_){
        Map<String, Integer> map = (HashMap<String, Integer>) map_;
        return  map.entrySet().stream()
                    .sorted(Map.Entry.<String, Integer>comparingByValue().reversed())
                        .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue,
                                (e1, e2) -> e1, LinkedHashMap::new));
    }

    public String getIndentation(String word, Integer maxLevel){
        String r = "";
        for (int i = 0; i < maxLevel - word.length() / 8; i++){
            r = r + "\t";
        }
        return r;
    }

    public Object printMap(Object map_, Integer maxRank){
        Map<String, Integer> map = (HashMap<String, Integer>) map_;
        Integer index = 0;
        Integer tabSize = 1;
        Integer keyMaxSize = 0;
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
        return map_;
    }

    public Object saveMap(Object map_, String filename){
        Map<String, Integer> map = (HashMap<String, Integer>) map_;
        Integer index = 0;
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

        return  map_;
    }
}
