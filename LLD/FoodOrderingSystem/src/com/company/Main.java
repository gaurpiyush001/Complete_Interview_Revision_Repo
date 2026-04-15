package com.company;

import com.company.constants.EvictionPolicy;
import com.company.model.Cache;
import com.company.service.CacheService;

public class Main {

    public static void main(String[] args) {
        CacheService cacheService= CacheService.getInstance();
        Cache cache = cacheService.init(10, EvictionPolicy.LRU);
        cacheService.put("HelloJi","First Project Done!!");
        System.out.println(cacheService.get("HelloJi"));
    }
}
