//
// Created by Administrator on 2019/6/6.
//
#include "jni.h"

#include "HelloWorld.h"
#ifdef _WIN32

#include <windows.h>

#else
#include <dlfcn.h>

#define DWORD unsigned int
#define __int64 long long
__int64 _atoi64(const char* val) {
    return strtoll(val, NULL, 10);
}
#endif

#include <iostream>

#ifndef GetProcAddress
#ifdef _WIN32
#define GetProcAddress GetProcAddress
#define CAST_TO_HINSTANCE (HINSTANCE)
#else
#define GetProcAddress dlsym
#define CAST_TO_HINSTANCE
#endif
#endif


#ifndef LoadLibraryImpl
#define LoadLibraryImpl
#ifndef _WIN32
void* LoadLibrary(const char* libName) {
            return dlopen(libName, RTLD_NOW);
        }
#endif
#endif
#ifndef GetProcAddress
#ifdef _WIN32
#define GetProcAddress GetProcAddress
#define CAST_TO_HINSTANCE (HINSTANCE)
#else
#define GetProcAddress dlsym
#define CAST_TO_HINSTANCE
#endif
#endif
HINSTANCE SelfHMODULE;
#ifdef _WIN32

BOOL APIENTRY DllMain(HINSTANCE hinst, DWORD raison, LPVOID reserv) {
    if (raison == DLL_PROCESS_ATTACH)
        SelfHMODULE = hinst;
    return TRUE;
}

#endif


using namespace std;

void searchFunction(void *hMod, const char *lFuncName, void **procAddress) {
    *procAddress = (void *) GetProcAddress(CAST_TO_HINSTANCE hMod, lFuncName);
    void *proc = *procAddress;
    if (!proc) {
        int num = /*sprintf("Function %s not found in DLL %s", lFuncName, lDllName) + 1*/1024;
        char *buf = new char[num + 1];
#ifdef WIN32
#if _MSC_VER >= 1400
        sprintf_s(buf, num, "Function %s not found", lFuncName);
#else
        sprintf(buf, "Function %s not found", lFuncName);
#endif
#else
        sprintf(buf, "Function %s not found in library", lFuncName);
#endif

        throw buf;
    } else {
        printf("<<<<<<<<<<<<<<<<<   %s loaded! >>>>>>>>>>>>>>>>>\n", lFuncName);
    }
}

void loadLib(const char *lDllName, const char *lFuncName, void **hModule, void **procAddress) {
/////////////  load the DLL //////////////////////////////////////
    printf("Trying to load library\n");


    *hModule = LoadLibrary(lDllName);
    void *hMod = *hModule;

    if (!hMod) {
        printf("Exception DLL\n");
        int num = /*sprintf("DLL %s not found", lDllName)+1*/1024;
        char *buf = new char[num + 1];

#ifdef _WIN32
        /**
         * _MSC_VER 定义编译器的版本。下面是一些编译器版本的_MSC_VER值。
            MS VC++ 12.0 _MSC_VER = 1800 (Visual C++ 2013)
            MS VC++ 11.0 _MSC_VER = 1700 (Visual C++ 2012)
            MS VC++ 10.0 _MSC_VER = 1600(Visual C++ 2010)
            MS VC++ 9.0 _MSC_VER = 1500
            MS VC++ 8.0 _MSC_VER = 1400
            MS VC++ 7.1 _MSC_VER = 1310
            MS VC++ 7.0 _MSC_VER = 1300
            MS VC++ 6.0 _MSC_VER = 1200
            MS VC++ 5.0 _MSC_VER = 1100

         */
#if _MSC_VER >= 1400//这个是ms vc的版本
        sprintf_s(buf, num, "DLL %s not found", lDllName);
#else
        sprintf(buf, "DLL %s not found", lDllName);
#endif
#else
        char* error = dlerror();
            if(!error) {
                error = "no message";
            }
            sprintf(buf, "Library %s not found : %s", lDllName, error);
#endif

        printf("%s\n", buf);
        throw buf;
        return;
    }
    searchFunction(hMod, lFuncName, procAddress);
}
/*
 * Class:     HelloWorld
 * Method:    init
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_HelloWorld_init(JNIEnv *env, jobject job, jint lPort){
    void* hModule = 0;
    void* pointer = 0;
    const char *cFunctionName="Initialize";
    const char *cLibName="HNBridge.dll";
    //加载library并寻找过程function
    loadLib(cLibName, cFunctionName, &hModule, &pointer);

    int returnedValue =0;
    int style = 2;
    int numBytes =10;
    //压栈

    //调用
    __asm__ __volatile__ (
    "call %[proc];\n\t"
    "movl %%eax, %[eax];\n\t"//Naturally in i386, the %eax holds the return value of functions
    "cmp $1, %[style];\n\t"
    "jne no_cdecl_ix;\n\t"
    "add %[nparam], %%esp;\n\t"
    "no_cdecl_ix:\n\t"
    : [eax] "=m" (returnedValue)
    : [proc] "g" (pointer), [style] "m" (style), [nparam] "r" (numBytes)
    :
    );
    cout<<"return value is:"<<returnedValue;
    return returnedValue;

}

/*
 * Class:     HelloWorld
 * Method:    print
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_HelloWorld_print(JNIEnv *env, jobject job, jstring str){
    printf("%s\n", str);
}

int main() {

    /*void **hModule;
    LoadLibrary("HNBridge.dll");
    void *hMod = *hModule;

    if (!hMod) {
        cout << "not exist!" << endl;
    } else {
        cout << "exist" << endl;
    }
    void *pointer = 0;


    const char *lFuncName = "Initialize";*/
    void* hModule = 0;
    void* pointer = 0;
    const char *cFunctionName="Initialize";
    const char *cLibName="HNBridge.dll";
    //加载library并寻找过程function,pointer就是函数指针
    loadLib(cLibName, cFunctionName, &hModule, &pointer);

    int returnedValue =0;
    int style = 2;
    int numBytes =10;
    //压栈

    //调用
    __asm__ __volatile__ (
    "call %[proc];\n\t"
    "movl %%eax, %[eax];\n\t"//Naturally in i386, the %eax holds the return value of functions
    "cmp $1, %[style];\n\t"
    "jne no_cdecl_i;\n\t"
    "add %[nparam], %%esp;\n\t"
    "no_cdecl_i:\n\t"
    : [eax] "=m" (returnedValue)
    : [proc] "g" (pointer), [style] "m" (style), [nparam] "r" (numBytes)
    :
    );
    cout<<"return value is:"<<returnedValue;
}


