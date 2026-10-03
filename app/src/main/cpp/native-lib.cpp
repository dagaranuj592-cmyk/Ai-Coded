#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_aicoded_LlamaEngine_nativeTest(
        JNIEnv* env,
        jobject /* thiz */) {

    std::string message =
            "llama.cpp native engine connected successfully";

    return env->NewStringUTF(message.c_str());
}
