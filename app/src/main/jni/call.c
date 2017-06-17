//
// Created by Administrator on 2017/6/16 0016.
//
#include "jni.h"
#include <android/log.h>
#define TAG "kkkkkk" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型

/**
当执行这个方法的时候，调用add（）方法
*/
JNIEXPORT void JNICALL Java_com_demo_ccalljava_JNI_callbackadd
  (JNIEnv * env, jobject jobj){
  //1.调用字节码
   jclass jclass1=(*env)->FindClass(env,"com/demo/ccalljava/JNI");
  //2.得到方法
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    //最后一个参数是方法签名   命令   Javap -s  com.demo.ccalljava.JNI(全类名)
//    C:\Users\Administrator\AndroidStudioProjects\CCallJava\app\build\intermediates\c
//    lasses\debug>javap -s com.demo.ccalljava.JNI
    jmethodID jmethodID1=(*env)->GetMethodID(env,jclass1,"add","(II)I");
  //3.实例化该类
    //jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject jobject1=(*env)->AllocObject(env,jclass1);
  //4.调用方法
    //jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
    jint val=(*env)->CallIntMethod(env,jobject1,jmethodID1,99,1);
//    printf("val===%d\n",val);
    //打印Log要加上最上面的导入      然后在Android.mk加上LOCAL_LDLIBS :=-llog
    LOGD("val===%d\n",val);
  }


//当执行这个方法的时候，调用sayHello()静态方法    可省略实例化这一步
JNIEXPORT void JNICALL Java_com_demo_ccalljava_JNI_callbacksayHello
        (JNIEnv * env, jobject jobj){

    //1.调用字节码
    jclass jclass1=(*env)->FindClass(env,"com/demo/ccalljava/JNI");
    //2.得到方法
    //jmethodID   (*GetStaticMethodID)(JNIEnv*, jclass, const char*, const char*);
    //最后一个参数是方法签名   命令   Javap -s  com.demo.ccalljava.JNI(全类名)
//    C:\Users\Administrator\AndroidStudioProjects\CCallJava\app\build\intermediates\c
//    lasses\debug>javap -s com.demo.ccalljava.JNI
    jmethodID jmethodID1=(*env)->GetStaticMethodID(env,jclass1,"sayHello","(Ljava/lang/String;)V");
    //3.实例化该类
    //jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject jobject1=(*env)->AllocObject(env,jclass1);
    //4.调用方法

    //jstring     (*NewStringUTF)(JNIEnv*, const char*);
    jstring jstring1=(*env)->NewStringUTF(env,"就亏吗");
    //void        (*CallStaticVoidMethod)(JNIEnv*, jclass, jmethodID, ...);
    (*env)->CallStaticVoidMethod(env,jclass1,jmethodID1,jstring1);
//    printf("val===%d\n",val);
    //打印Log要加上最上面的导入      然后在Android.mk加上LOCAL_LDLIBS :=-llog
//    LOGD("val===%d\n",val);
}


JNIEXPORT void JNICALL
Java_com_demo_ccalljava_MainActivity_callbackshowToast(JNIEnv *env, jobject instance) {

    jclass jclass1=(*env)->FindClass(env,"com/demo/ccalljava/MainActivity");
    jmethodID jmethodID1=(*env)->GetMethodID(env,jclass1,"showToast","()V");
    (*env)->CallVoidMethod(env,instance,jmethodID1);

}