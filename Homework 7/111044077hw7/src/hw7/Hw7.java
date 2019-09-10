/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw7;

import javafx.util.Pair;

/**
 *
 * @author mesut
 */
public class Hw7 {

    /**
     * Project test
     *
     * @param args the command line arguments input array
     * @throws java.lang.Exception for exception handling
     */
    public static void main(String[] args) throws Exception {
        try {
            GTUMap<Integer, Integer> mp = new GTUMap(Pair.class, 10);
            Pair<Integer, Integer> b = new Pair<>(1, 2);
            Pair<Integer, Integer> c = new Pair<>(3, 4);
            mp.insert(b);
            mp.insert(c);
            System.out.println("Map element : " + mp.at(1));
            System.out.println("Map element : " + mp.at(3));
            System.out.println("--------------------------------");

            GTUMap<String, String> mp2 = new GTUMap(Pair.class, 10);
            Pair<String, String> d = new Pair<>("mesut", "bunaldı");
            Pair<String, String> e = new Pair<>("hasan", "ulu");
            Pair<String, String> f = new Pair<>("halil", "ulusoy");
            mp2.insert(d);
            mp2.insert(e);
            mp2.insert(f);

            GTUMap<String, String> mp3 = new GTUMap(Pair.class, 10);
            Pair<String, String> g = new Pair<>("mesut", "bunaldı");
            Pair<String, String> z = new Pair<>("hasanaa", "uludd");
            Pair<String, String> w = new Pair<>("halil", "ulusoy");
            mp3.insert(g);
            mp3.insert(z);
            mp3.insert(w);
            System.out.println("Map element : " + mp2.at("hasan"));
            System.out.println("Map element : " + mp2.at("mesut"));
            System.out.println("Map element : " + mp2.at("halil"));
            System.out.println("--------------------------------");

            GTUMap<String, String> strResultMap = new GTUMap(Object.class, 10);

            strResultMap = (GTUMap<String, String>) mp2.intersection(mp3);

            System.out.println("Map result : " + strResultMap.at("mesut"));

//System.out.println("Result of Map find (value of iterator) : "+mp2.find("mesut").next().getValue()); 
            mp2.erase("mesut");
            System.out.println("Map element : " + mp2.at("hasan"));
            System.out.println("Map element : " + mp2.at("mesut"));
            System.out.println("Map element : " + mp2.at("halil"));
            //------------------------------------------------------//
            System.out.println("--------------------------------");
            GTUSet<Integer> a = new GTUSet<>(Integer.class, 10);
            a.insert(2);
            a.insert(54);
            a.insert(5);
            a.insert(524);

            GTUSet<Integer> m = new GTUSet<>();
            GTUSet<Integer>.GTUIterator<Integer> itr;
            itr = m.new GTUIterator<>(a.elements);

            itr = a.begin();

            while (itr.hasNext()) {
                System.out.println(itr.next());
            }

            //------------------------------------------------------//
            System.out.println("--------------------------------");
            GTUSet<Double> dblSet = new GTUSet<>(Double.class, 10);
            dblSet.insert(223.2);
            dblSet.insert(154.6);
            dblSet.insert(125.3);
            dblSet.insert(5234.2);
            GTUSet<Double> dblM = new GTUSet<>();
            GTUSet<Double>.GTUIterator<Double> itrDbl;
            itrDbl = dblM.new GTUIterator<>(dblSet.elements);

            itrDbl = dblSet.begin();

            while (itrDbl.hasNext()) {
                System.out.println(itrDbl.next());
            }
            //------------------------------------------------------//
            System.out.println("--------------------------------");
            GTUSet<String> strSet = new GTUSet<>(String.class, 20);
            strSet.insert("mesut");
            strSet.insert("mesutada");
            strSet.insert("mesut bunaldı");
            strSet.insert("ahmet");
            strSet.insert("mehmet");
            strSet.insert("veli");

            GTUSet<String> strM = new GTUSet<>();
            GTUSet<String>.GTUIterator<String> itrStr;
            GTUSet<String>.GTUIterator<String> itrStr2;
            itrStr = strM.new GTUIterator<>(strSet.elements);

            itrStr = strSet.begin();
            itrStr2 = strSet.end();

            while (itrStr.hasNext()) {
                System.out.println(itrStr.next());
            }
            System.out.println("-------------------------------------------------------");
            while (itrStr2.hasPrevious()) {
                System.out.println(itrStr2.previous());
            }

            itrStr = strSet.find("mesut bunaldı");
            System.out.println("----------------------------------------------------");
            while (itrStr.hasNext()) {
                System.out.println(itrStr.next());
            }

        } catch (Exception e) {
            System.out.println("Error : " + e.toString());
        }

        try {
            GTUSet<Integer> t = new GTUSet<>(Integer.class, 5);
            t.insert(2);
            t.insert(12);
            t.insert(54);
            t.insert(124);

            GTUSet<Integer> k = new GTUSet<>(Integer.class, 5);
            k.insert(2);
            k.insert(77);
            k.insert(12);
            k.insert(123);
            k.insert(124);
            k.insert(125);

            GTUSet<Integer> resultIntersection = k.intersection(t);

            GTUSet<Integer>.GTUIterator<Integer> itrResult;

            itrResult = resultIntersection.begin();
            while (itrResult.hasNext()) {
                System.out.println("Intersection result : " + itrResult.next());
            }

        } catch (Exception e) {
            System.out.println("Error : " + e.toString());
        }

    }

}
