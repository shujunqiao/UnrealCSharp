﻿#pragma once

#include "GarbageCollection/TGarbageCollectionHandleMapping.inl"
#include "GarbageCollection/TMonoObjectMapping.inl"

struct FBindingAddressWrapper
{
	virtual ~FBindingAddressWrapper()
	{
	}

	virtual void* GetValue()
	{
		return nullptr;
	}
};

template <typename T>
struct TBindingAddressWrapper : FBindingAddressWrapper
{
	explicit TBindingAddressWrapper(T* InValue): Value(InValue)
	{
	}

	virtual ~TBindingAddressWrapper() override
	{
		delete Value;
	}

	virtual void* GetValue() override
	{
		return (void*)Value;
	}

private:
	T* Value;
};

struct FBindingAddress
{
	FBindingAddressWrapper* AddressWrapper;

	bool bNeedFree;

	FBindingAddress(FBindingAddressWrapper* InAddressWrapper, const bool InNeedFree = true):
		AddressWrapper(InAddressWrapper),
		bNeedFree(InNeedFree)
	{
	}
};

static bool operator==(const FBindingAddress& A, const FBindingAddress& B);

static uint32 GetTypeHash(const FBindingAddress& InBindingAddress);

class UNREALCSHARP_API FBindingRegistry
{
public:
	FBindingRegistry();

	~FBindingRegistry();

public:
	void Initialize();

	void Deinitialize();

public:
	template <typename T>
	auto GetBinding(const FGarbageCollectionHandle& InGarbageCollectionHandle);

	template <typename T>
	auto GetBinding(const MonoObject* InMonoObject);

	MonoObject* GetObject(const void* InObject);

public:
	template <typename T>
	auto AddReference(const T* InObject, MonoObject* InMonoObject, bool bNeedFree = true);

	bool RemoveReference(const FGarbageCollectionHandle& InGarbageCollectionHandle);

private:
	TGarbageCollectionHandleMapping<FBindingAddress> GarbageCollectionHandle2BindingAddress;

	TMap<void*, FGarbageCollectionHandle> BindingAddress2GarbageCollectionHandle;

	TMonoObjectMapping<FBindingAddress> MonoObject2BindingAddress;
};

#include "FBindingRegistry.inl"
