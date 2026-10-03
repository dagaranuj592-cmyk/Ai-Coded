package com.example.aicoded;

public class LlamaEngine {

    static {
        System.loadLibrary("aicoded");
    }

    public native boolean loadModel(String modelPath);

    public native String generate(
            String prompt,
            int maxTokens
    );

    public native void unloadModel();

    public boolean isReady() {
        return true;
    }
}
