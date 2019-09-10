/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw7;

import java.security.InvalidParameterException;

/**
 *
 * @author mesut
 * @param <T>
 *
 */
public interface GTUSetInt<T> {

    /**
     * statement of empty
     *
     * @return
     */
    public boolean empty();

    /**
     * statement of used size
     *
     * @return
     */
    public int size();

    /**
     * statement of capacity
     *
     * @return
     */
    public int max_size();

    /**
     * parameter of insert for new item
     *
     * @param element parameter of insert for new item
     * @throws Exception for catching
     */
    public void insert(T element) throws Exception;

    /**
     *
     * @param setVal set object for compare
     * @return return an object (set object)
     */
    public GTUSetInt<T> intersection(GTUSetInt<T> setVal);

    /**
     *
     * @param element element parameter for delete
     * @return if successful return 1 else 0
     */
    public int erase(T element);

    /**
     *
     */
    public void clear();

    /**
     *
     *
     * @param val for searching
     * @return return iterator
     */
    public T find(T val);

    /**
     *
     * @param val
     * @return
     */
    public int count(T val);

    /**
     *
     * @return return iterator
     */
    public GTUSet<T>.GTUIterator<T> begin();

    /**
     *
     * @return return iterator
     */
    public GTUSet<T>.GTUIterator<T> end();

}
