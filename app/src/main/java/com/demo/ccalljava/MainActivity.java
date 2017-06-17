package com.demo.ccalljava;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {

    private JNI jni;
    private TextView text;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        jni =new JNI();
        text= (TextView) findViewById(R.id.text);
    }

    public native void callbackshowToast();

    public void showToast(){
        Log.d("kkkkkkk","ggggggggggg");
        text.setText("2222222");
        Toast.makeText(MainActivity.this,"哈哈哈哈哈",Toast.LENGTH_SHORT).show();
    }

    public void add(View view){
        jni.callbackadd();
    }

    public void st(View view){
        jni.callbacksayHello();
    }

    public void to(View view){
        MainActivity.this.callbackshowToast();
    }
}
