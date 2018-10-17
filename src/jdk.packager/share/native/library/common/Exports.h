/*
 * Copyright (c) 2014, 2018, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  Oracle designates this
 * particular file as subject to the "Classpath" exception as provided
 * by Oracle in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 */

/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class jdk_packager_services_userjvmoptions_LauncherUserJvmOptions */

#ifndef _Included_jdk_packager_services_userjvmoptions_LauncherUserJvmOptions
#define _Included_jdk_packager_services_userjvmoptions_LauncherUserJvmOptions
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     jdk_packager_services_userjvmoptions_LauncherUserJvmOptions
 * Method:    _getUserJvmOptionDefaultValue
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL
        Java_jdk_packager_services_userjvmoptions_LauncherUserJvmOptions__1getUserJvmOptionDefaultValue(
        JNIEnv *, jclass, jstring);

/*
 * Class:     jdk_packager_services_userjvmoptions_LauncherUserJvmOptions
 * Method:    _getUserJvmOptionDefaultKeys
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL
        Java_jdk_packager_services_userjvmoptions_LauncherUserJvmOptions__1getUserJvmOptionDefaultKeys(
        JNIEnv *, jclass);

/*
 * Class:     jdk_packager_services_userjvmoptions_LauncherUserJvmOptions
 * Method:    _getUserJvmOptionValue
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL
        Java_jdk_packager_services_userjvmoptions_LauncherUserJvmOptions__1getUserJvmOptionValue(
        JNIEnv *, jclass, jstring);

/*
 * Class:     jdk_packager_services_userjvmoptions_LauncherUserJvmOptions
 * Method:    _setUserJvmKeysAndValues
 * Signature: ([Ljava/lang/String;[Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL
        Java_jdk_packager_services_userjvmoptions_LauncherUserJvmOptions__1setUserJvmKeysAndValues(
        JNIEnv *, jclass, jobjectArray, jobjectArray);

/*
 * Class:     jdk_packager_services_userjvmoptions_LauncherUserJvmOptions
 * Method:    _getUserJvmOptionKeys
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL
        Java_jdk_packager_services_userjvmoptions_LauncherUserJvmOptions__1getUserJvmOptionKeys(
        JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif
