#include <jni.h>
#include <string>
#include "llama.h"

static llama_model * model = nullptr;
static llama_context * context = nullptr;

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_example_aicoded_LlamaEngine_loadModel(
        JNIEnv *env,
        jobject,
        jstring jModelPath) {

    const char *modelPath = env->GetStringUTFChars(jModelPath, nullptr);

    llama_backend_init();

    llama_model_params modelParams = llama_model_default_params();

    model = llama_load_model_from_file(
            modelPath,
            modelParams
    );

    env->ReleaseStringUTFChars(jModelPath, modelPath);

    if (model == nullptr) {
        return JNI_FALSE;
    }

    llama_context_params contextParams =
            llama_context_default_params();

    contextParams.n_ctx = 2048;
    contextParams.n_batch = 512;
    contextParams.n_threads = 4;
    contextParams.n_threads_batch = 4;

    context = llama_new_context_with_model(
            model,
            contextParams
    );

    if (context == nullptr) {
        llama_free_model(model);
        model = nullptr;
        return JNI_FALSE;
    }

    return JNI_TRUE;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_aicoded_LlamaEngine_generate(
        JNIEnv *env,
        jobject,
        jstring jPrompt,
        jint maxTokens) {

    if (model == nullptr || context == nullptr) {
        return env->NewStringUTF(
                "Error: model is not loaded."
        );
    }

    return env->NewStringUTF(
            "Engine loaded. Generation bridge is ready."
    );
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_aicoded_LlamaEngine_unloadModel(
        JNIEnv *,
        jobject) {

    if (context != nullptr) {
        llama_free(context);
        context = nullptr;
    }

    if (model != nullptr) {
        llama_free_model(model);
        model = nullptr;
    }

    llama_backend_free();
}
