package com.company.model;

import com.company.constants.EvictionPolicy;

import java.util.HashMap;
import java.util.LinkedList;

public class Cache {
    private int size;
    private EvictionPolicy evictionPolicy;
    private LinkedList<Object> dataStore;
    private HashMap<Object,Object> cacheStore;

    public Cache(int size, EvictionPolicy evictionPolicy){
        this.size=size;
        this.evictionPolicy=evictionPolicy;
        this.dataStore=new LinkedList<>();
        this.cacheStore=new HashMap<>();
    }

    public Boolean clear(){
        try {
            this.dataStore=new LinkedList<>();
            this.cacheStore=new HashMap<>();
            return true;
        }
        catch (Exception e){
            System.out.println("Something went wrong while Clearing cache");

        }
        return false;
    }
    public int getSize() {
        return size;
    }

    public EvictionPolicy getEvictionPolicy() {
        return evictionPolicy;
    }

    public LinkedList<Object> getDataStore() {
        return dataStore;
    }

    public HashMap<Object, Object> getCacheStore() {
        return cacheStore;
    }

}