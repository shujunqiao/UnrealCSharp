﻿using System;
using System.Runtime.CompilerServices;

namespace Script.Library
{
    public static unsafe class FDelegateImplementation
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void FDelegate_RegisterImplementation(object InMonoObject);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void FDelegate_UnRegisterImplementation(nint InMonoObject);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void FDelegate_BindImplementation<T>(nint InMonoObject, nint InObject, T InDelegate)
            where T : Delegate;

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern bool FDelegate_IsBoundImplementation(nint InMonoObject);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void FDelegate_UnBindImplementation(nint InMonoObject);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void FDelegate_ClearImplementation(nint InMonoObject);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void FDelegate_GenericExecute0Implementation(nint InMonoObject);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void FDelegate_PrimitiveExecute1Implementation(nint InMonoObject,
            byte* ReturnBuffer);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void FDelegate_CompoundExecute1Implementation(nint InMonoObject,
            byte* ReturnBuffer);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void FDelegate_GenericExecute2Implementation(nint InMonoObject,
            byte* InBuffer);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void FDelegate_PrimitiveExecute3Implementation(nint InMonoObject,
            byte* InBuffer, byte* ReturnBuffer);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void FDelegate_CompoundExecute3Implementation(nint InMonoObject,
            byte* InBuffer, byte* ReturnBuffer);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void FDelegate_GenericExecute4Implementation(nint InMonoObject,
            byte* OutBuffer);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void FDelegate_GenericExecute6Implementation(nint InMonoObject,
            byte* InBuffer, byte* OutBuffer);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void FDelegate_PrimitiveExecute7Implementation(nint InMonoObject,
            byte* InBuffer, byte* OutBuffer, byte* ReturnBuffer);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void FDelegate_CompoundExecute7Implementation(nint InMonoObject,
            byte* InBuffer, byte* OutBuffer, byte* ReturnBuffer);
    }
}