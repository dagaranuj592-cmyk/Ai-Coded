package com.example.aicoded;

public class LlamaEngine {

    static {
        System.loadLibrary("aicoded");
    }

    public native String nativeTest();

    public String testEngine() {
        return nativeTest();
    }
}
