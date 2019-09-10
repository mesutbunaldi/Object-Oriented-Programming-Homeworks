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
 *
 */
public class GTUMap<K, V> extends GTUSet<Pair<K, V>> {

    /**
     *
     * @param element
     * @param capacity
     */
    public GTUMap(Class<Pair<K, V>> element, int capacity) {
        super(element, capacity);
    }

    /**
     *
     * @param otherSet
     * @return
     * @throws Exception
     */
    public GTUMap<K, V> intersection(GTUMap<K, V> otherSet) throws Exception {

        GTUMap<K, V> temp = new GTUMap(Pair.class, 10);

        GTUIterator<Pair<K, V>> myItr = begin();
        GTUIterator<Pair<K, V>> itrOther = otherSet.begin();
        if (myItr.hasNext() && itrOther.hasNext()) {
            for (int i = 0; i < size(); i++) {
                for (int j = 0; j < otherSet.size(); j++) {
                    if (elements[i].getKey() == otherSet.elements[j].getKey()) {
                        System.out.println(elements[i].getValue());
                        temp.insert(elements[i]);

                    }
                }
            }
        }
        return temp;
    }

    /**
     *
     * @param element
     * @return
     */
    @Override
    public int erase(Object element) {
        for (int i = 0; i < size(); ++i) {
            if (elements[i].getKey() == element) {
                elements[i] = elements[size() - 1];
                --used;
                return 1;
            }
        }
        return 0;
    }

    /**
     *
     * @param val
     * @return
     */
    @Override
    public GTUIterator<Pair<K, V>> find(Object val) {
        GTUIterator<Pair<K, V>> itr = (GTUIterator<Pair<K, V>>) begin();

        while (itr.hasNext()) {
            if (itr.next().getKey() == val) {
                return itr;
            }
        }
        return null;
    }

    /**
     *
     * @param k
     * @return
     */
    public V at(K k) {
        for (int c = 0; c <= this.size(); c++) {
            if (elements[c].getKey() == k) {
                return (V) this.elements[c].getValue();
            }
        }
        return null;

    }
}
