package com.company;

import java.util.Scanner;

public class Display {

    public Display(){
    }

    public String requestInput(String message){
        Scanner scanner = new Scanner(System.in);
        System.out.print(message);
        return scanner.nextLine();
    }

    public Integer requestChoice(String message, int highRange){
        Integer choice = 0;
        System.out.println(message);
        while(choice < 1 || choice > highRange){
            choice = Integer.valueOf(requestInput("Enter a choice: "));
            if (choice < 1 || choice > 9){
                System.out.println("Choice not available, try again.");
            }
        }
        return choice;
    }
}
