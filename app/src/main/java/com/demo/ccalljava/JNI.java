package com.demo.ccalljava;

import android.util.Log;

/**
 * Created by Administrator on 2017/6/16 0016.
 */

public class JNI {

    {
        System.loadLibrary("call");
    }

    /**
     * 当执行这个方法的时候，调用add（）方法
     */
    public native void callbackadd();

    /**
     * 当执行这个方法的时候，调用sayHello()静态方法
     */
    public native void callbacksayHello();


//    public native void callbacksayGetHaha();//Alt+Enter快捷键在C里面生成对应方法


    public int add(int a,int b){
        Log.d("kkkkkkk",a+"     "+b);
        return a+b;
    }

    public static void sayHello(String s){
        Log.d("kkkkkk","港沪港版的汇聚关火即可改变");
    }

//    public int getHaha(int a,int b){
//        Log.d("kkkkkkk",a+"     "+b);
//        return a+b;
//    }
}
