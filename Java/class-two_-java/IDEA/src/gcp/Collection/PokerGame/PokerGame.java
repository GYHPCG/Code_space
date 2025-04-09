package gcp.Collection.PokerGame;

import java.util.ArrayList;
import java.util.Collections;

public class PokerGame {
    /*
    * 1.准备一副牌，list1放花色，list2放数字
    *   花色：♠,♣,♦,♥
    *
    * 2.因为不管玩多少次，用的还是一副牌，所以牌放在静态代码块里
    * */
    //一副牌
    static ArrayList<String> list = new ArrayList<>();
    static {
        //花色
        String[] color = {"♣","♠","♦","♥"};
        //数字
        String[] number = {"3","4","5","6","7","8","9","10","J","Q","K","A","2"};
        //花色和数字组合
        for (String co : color) {
            for (String n : number) {
                list.add(co + n);
            }
        }
        //大小王
        list.add("小王");
        list.add("大王");
        
    }

    public  PokerGame() {
        //System.out.println(list);
        //打乱牌
        Collections.shuffle(list);

        //发牌
        ArrayList<String> lord = new ArrayList<>();//底牌
        ArrayList<String> player1 = new ArrayList<>();
        ArrayList<String> player2 = new ArrayList<>();
        ArrayList<String> player3 = new ArrayList<>();

        for (int i = 0; i < list.size(); i++) {
            if (i < 3) {
                lord.add(list.get(i));
            }

            //给三个玩家发牌
            if (i % 3 == 0) {
                player1.add(list.get(i));
            } else if (i % 3 == 2) {
                player2.add(list.get(i));
            } else {
                player3.add(list.get(i));
            }
        }

        lookPoker("底牌",lord);
        lookPoker("小王",player1);
        lookPoker("李华",player2);
        lookPoker("张三",player3);

    }

    //看牌
    public void lookPoker(String name, ArrayList<String> list) {
        System.out.print(name + ": ");
        for (String s : list) {
            System.out.print(s + " ");
        }
        System.out.println();
    }


}
