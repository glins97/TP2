package com.company;

import java.util.Scanner;

public class Display {

    public Display(){
    }

    public String requestInput(String message){
        assert message.length() != 0: "Message must have at least one letter!";
        Scanner scanner = new Scanner(System.in);
        System.out.print(message);
        return scanner.nextLine();
    }
}
