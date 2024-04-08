package com.company.dao;
import com.company.constants.EvictionPolicy;
import com.company.model.Cache;

import java.util.HashMap;
import java.util.LinkedList;

public class CacheDao {
    private static CacheDao cacheDao=null;
    private Cache cache=null;
    private CacheDao(){

    }
    public static CacheDao getInstance(){
        if(cacheDao==null){
            cacheDao=new CacheDao();
        }
        return cacheDao;
    }

    public Cache createCache(int size, EvictionPolicy evictionPolicy){
        cache= new Cache(size,evictionPolicy);
        return cache;
    }

    public Object get(Object obj){
        Object result= cache.getCacheStore().get(obj);

        //if obj does not exit, then return null
        if(result==null)
            return  null;

        //if obj exists, return result
        // update data store, in acoordance to Eviction Policy
        cache.getDataStore().remove(obj);
        cache.getDataStore().addFirst(obj);
        return result;

    }

    public Boolean put(Object key, Object val){
        try {
            //check if we have empty spaces in cache
            if (cache.getSize() == cache.getDataStore().size()) {
                Object last = cache.getDataStore().removeLast();
                cache.getCacheStore().remove(last);
            }
            //remove key from LL if exist beforehand
            cache.getDataStore().remove(key);
            //place it in front
            cache.getDataStore().addFirst(key);
            //insert into map
            cache.getCacheStore().put(key, val);
            return true;
        }
        catch (Exception e){
            System.out.println("Something went wrong while adding element");
        }
        return false;
    }
    public Boolean delete(Object obj){
        if(cache.getDataStore().size()==0 ) return true;

        try {
            cache.getDataStore().remove(obj);
            cache.getCacheStore().remove(obj);
            return true;
        }
        catch (Exception e){
            System.out.println("Something went wrong while removing element");
        }
        return false;
    }
    public  Boolean clear(){
        return cache.clear();
    }
}