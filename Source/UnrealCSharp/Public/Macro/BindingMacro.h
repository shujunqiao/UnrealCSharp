﻿#pragma once

#include "CoreMacro/BindingMacro.h"
#include "Binding/Function/TFunctionBuilder.inl"
#include "Binding/Function/FFunctionPointer.h"

#define WITH_PROPERTY_INFO WITH_EDITOR

#define WITH_FUNCTION_INFO WITH_EDITOR

#define BINDING_STR(Str) #Str

#define BINDING_REMOVE_PREFIX_CLASS_STR(Class) BINDING_REMOVE_PREFIX_CLASS(FString(TEXT(BINDING_STR(Class))))

#define BINDING_CLASS(Class) \
template <> \
struct TClassName<Class> \
{ \
	static FString Get() { return BINDING_REMOVE_PREFIX_CLASS_STR(Class); } \
};

#define BINDING_PROPERTY_BUILDER_SET(Property) TPropertyBuilder<decltype(Property), Property>::Set

#define BINDING_PROPERTY_BUILDER_GET(Property) TPropertyBuilder<decltype(Property), Property>::Get

#define BINDING_PROPERTY_BUILDER_INFO(Property) TPropertyBuilder<decltype(Property), Property>::Info()

#if WITH_PROPERTY_INFO
#define BINDING_PROPERTY(Property) BINDING_PROPERTY_BUILDER_GET(Property), BINDING_PROPERTY_BUILDER_SET(Property), BINDING_PROPERTY_BUILDER_INFO(Property)
#else
#define BINDING_PROPERTY(Property) BINDING_PROPERTY_BUILDER_GET(Property), BINDING_PROPERTY_BUILDER_SET(Property)
#endif

#if WITH_PROPERTY_INFO
#define BINDING_READONLY_PROPERTY(Property) BINDING_PROPERTY_BUILDER_GET(Property), nullptr, BINDING_PROPERTY_BUILDER_INFO(Property)
#else
#define BINDING_READONLY_PROPERTY(Property) BINDING_PROPERTY_BUILDER_GET(Property), nullptr
#endif

#define BINDING_FUNCTION_BUILDER_INVOKE(Function) \
	FFunctionPointer([](BINDING_FUNCTION_SIGNATURE) \
	{ \
	TFunctionBuilder<decltype(Function), Function>::Invoke(BINDING_FUNCTION_PARAM); \
	}).Value.Pointer

#define BINDING_FUNCTION_BUILDER_INFO(Function) TFunctionBuilder<decltype(Function), Function>::Info()

#if WITH_FUNCTION_INFO
#define BINDING_FUNCTION(Function) BINDING_FUNCTION_BUILDER_INVOKE(Function), BINDING_FUNCTION_BUILDER_INFO(Function)
#else
#define BINDING_FUNCTION(Function) BINDING_FUNCTION_BUILDER_INVOKE(Function)
#endif
