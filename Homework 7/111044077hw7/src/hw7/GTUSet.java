/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw7;

import hw7.GTUSet.GTUIterator;
import static java.lang.System.exit;
import java.lang.reflect.Array;
import java.security.InvalidParameterException;
import java.util.Arrays;

/**
 *
 * @author mesut
 *
 */
public class GTUSet<T> implements GTUSetInt {

    //my data members
    public T[] elements;
    public int used;
    public int capacity;

    /**
     *
     * @param setVal
     * @return
     */
    @Override
    public GTUSetInt intersection(GTUSetInt setVal) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    //inner class
    //////////////////////////////////////////////////////////////////////////////////////////////
    //public class Position implements Iterable<Position>
    public class GTUIterator<T> {

        int currentB = 0;
        int currentE = used - 1;
        T[] p;

        /**
         *
         * @param x
         */
        public GTUIterator(T[] x) {

            p = (T[]) Array.newInstance(Object.class, capacity);
            p = x;

        }

        //        
        //      
        /**
         * dsıorfsıdsıodmfos
         *
         * @return sdfmksodfsd
         */
        public boolean hasNext() {
            return (boolean) (currentB < used);
        }

        /**
         *
         * @return
         */
        public boolean hasPrevious() {
            return (boolean) (currentE > -1);
        }

        /**
         *
         * @return
         */
        public T next() {
            if (hasNext() == true) {
                return p[currentB++];
            }
            return null;

        }

        /**
         *
         * @return
         */
        public T previous() {
            if (hasPrevious() == true) {
                return (T) elements[currentE--];
            }
            return null;
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////
    /**
     * Constructor
     *
     * @param element for initialization
     * @param capacity for initialization
     */
    public GTUSet(Class<T> element, int capacity) {
        this.capacity = capacity;
        used = 0;
        elements = (T[]) Array.newInstance(element, capacity);

    }

    /**
     * constructor
     */
    public GTUSet() {
        this.capacity = 10;
        used = 0;
        elements = (T[]) Array.newInstance(Object.class, capacity);
    }

    /**
     *
     */
    @Override
    public boolean empty() {
        if (used == 0) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * Used of elements
     *
     * @return Used of elements
     */
    @Override
    public int size() {
        return used;
    }

    /**
     * Capacity of elements
     *
     * @return capacity of elements
     */
    @Override
    public int max_size() {
        return capacity;
    }

    /**/
    /**
     *
     * @param element
     *
     *
     * @throws java.lang.Exception
     */
    @Override
    public void insert(Object element) throws Exception {
        if (count(element) == 0) {//eleman yoksa bu işleme gir      
            if (size() <= max_size() - 1) {
                elements[used] = (T) element;
                used++;
            } else {

                capacity += 10;
                T[] temp = (T[]) Array.newInstance(element.getClass(), capacity);
                for (int i = 0; i < size(); ++i) {
                    temp[i] = elements[i];
                }
                elements = (T[]) Array.newInstance(element.getClass(), capacity);
                elements = temp;
                elements[used] = (T) element;
                used++;
            }
        } else {
            throw new Exception("Same element!\n");

        }
    }

    /**
     *
     * @param otherSet Parameter of intersection for compare elements
     * @return return GTUSet object for intersection
     * @throws Exception if we try insert same elements its gonna be usable
     */
    public GTUSet<T> intersection(GTUSet<T> otherSet) throws Exception {
        GTUSet<T> temp = new GTUSet<>((Class<T>) Object.class, 10);
        GTUIterator<T> myItr = begin();
        GTUIterator<T> itrOther = otherSet.begin();
        if (myItr.hasNext() && itrOther.hasNext()) {
            for (int i = 0; i < size(); i++) {
                for (int j = 0; j < otherSet.size(); j++) {
                    if (elements[i] == otherSet.elements[j]) {
                        temp.insert(elements[i]);
                    }
                }
            }
        }
        return temp;
    }

    /**
     *
     * @param element Value for erase
     * @return if we erased element 1 else 0
     */
    @Override
    public int erase(Object element) {
        for (int i = 0; i < size(); ++i) {
            if (elements[i] == element) {
                elements[i] = elements[size() - 1];
                --used;
                return 1;
            }
        }
        return 0;
    }

    /**
     *
     */
    @Override
    public void clear() {
        Arrays.fill(elements, null);
        used = 0;
    }

    /**
     *
     * @param val its key for search
     * @return iterator for element address
     */
    @Override
    public GTUIterator<T> find(Object val) {
        GTUIterator<T> itr = begin();
        GTUIterator<T> n;
        while (itr.hasNext()) {
            if (itr.next() == val) {
                return itr;
            }
        }
        return null;
    }

    /**
     *
     * @param val
     * @return
     */
    @Override
    public int count(Object val) {
        for (int j = 0; j < size(); j++) {
            if (elements[j] == val) {
                return 1;
            }
        }
        return 0;
    }

    /**
     *
     * @return
     */
    @Override
    public GTUIterator<T> begin() {
        GTUIterator<T> n;
        n = new GTUIterator<>(elements);
        return n;
    }

    /**
     *
     * @return
     */
    @Override
    public GTUIterator<T> end() {
        GTUIterator<T> n;
        n = new GTUIterator<>((T[]) elements[used]);
        return n;
    }

}
