/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

_WdfVersionBuild_

Module Name:

    WdfDmaEnabler.h

Abstract:

    WDF DMA Enabler support

Environment:

    Kernel mode only.

Notes:

Revision History:

--*/

//
// NOTE: This header is generated by stubwork.  Please make any 
//       modifications to the corresponding template files 
//       (.x or .y) and use stubwork to regenerate the header
//

#ifndef _WDFDMAENABLER_H_
#define _WDFDMAENABLER_H_

#ifndef WDF_EXTERN_C
  #ifdef __cplusplus
    #define WDF_EXTERN_C       extern "C"
    #define WDF_EXTERN_C_START extern "C" {
    #define WDF_EXTERN_C_END   }
  #else
    #define WDF_EXTERN_C
    #define WDF_EXTERN_C_START
    #define WDF_EXTERN_C_END
  #endif
#endif

WDF_EXTERN_C_START



#if (NTDDI_VERSION >= NTDDI_WIN2K)

typedef enum _WDF_DMA_PROFILE {
    WdfDmaProfileInvalid = 0,
    WdfDmaProfilePacket,
    WdfDmaProfileScatterGather,
    WdfDmaProfilePacket64,
    WdfDmaProfileScatterGather64,
    WdfDmaProfileScatterGatherDuplex,
    WdfDmaProfileScatterGather64Duplex,
    WdfDmaProfileSystem,
    WdfDmaProfileSystemDuplex,
} WDF_DMA_PROFILE;

typedef enum _WDF_DMA_DIRECTION {
    WdfDmaDirectionReadFromDevice = FALSE,
    WdfDmaDirectionWriteToDevice = TRUE,
} WDF_DMA_DIRECTION;



//
// DMA power event callbacks
//
typedef
_Function_class_(EVT_WDF_DMA_ENABLER_FILL)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_WDF_DMA_ENABLER_FILL(
    _In_
    WDFDMAENABLER DmaEnabler
    );

typedef EVT_WDF_DMA_ENABLER_FILL *PFN_WDF_DMA_ENABLER_FILL;

typedef
_Function_class_(EVT_WDF_DMA_ENABLER_FLUSH)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_WDF_DMA_ENABLER_FLUSH(
    _In_
    WDFDMAENABLER DmaEnabler
    );

typedef EVT_WDF_DMA_ENABLER_FLUSH *PFN_WDF_DMA_ENABLER_FLUSH;

typedef
_Function_class_(EVT_WDF_DMA_ENABLER_ENABLE)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_WDF_DMA_ENABLER_ENABLE(
    _In_
    WDFDMAENABLER DmaEnabler
    );

typedef EVT_WDF_DMA_ENABLER_ENABLE *PFN_WDF_DMA_ENABLER_ENABLE;

typedef
_Function_class_(EVT_WDF_DMA_ENABLER_DISABLE)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_WDF_DMA_ENABLER_DISABLE(
    _In_
    WDFDMAENABLER DmaEnabler
    );

typedef EVT_WDF_DMA_ENABLER_DISABLE *PFN_WDF_DMA_ENABLER_DISABLE;

typedef
_Function_class_(EVT_WDF_DMA_ENABLER_SELFMANAGED_IO_START)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_WDF_DMA_ENABLER_SELFMANAGED_IO_START(
    _In_
    WDFDMAENABLER DmaEnabler
    );

typedef EVT_WDF_DMA_ENABLER_SELFMANAGED_IO_START *PFN_WDF_DMA_ENABLER_SELFMANAGED_IO_START;

typedef
_Function_class_(EVT_WDF_DMA_ENABLER_SELFMANAGED_IO_STOP)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_WDF_DMA_ENABLER_SELFMANAGED_IO_STOP(
    _In_
    WDFDMAENABLER DmaEnabler
    );

typedef EVT_WDF_DMA_ENABLER_SELFMANAGED_IO_STOP *PFN_WDF_DMA_ENABLER_SELFMANAGED_IO_STOP;


#define  WDF_DMA_ENABLER_UNLIMITED_FRAGMENTS ((ULONG) -1)

typedef enum _WDF_DMA_ENABLER_CONFIG_FLAGS {
    //
    // This flag only applies to the following DMA profiles:
    //  WdfDmaProfileScatterGather,
    //  WdfDmaProfileScatterGather64,
    //  WdfDmaProfileScatterGatherDuplex and
    //  WdfDmaProfileScatterGather64Duplex
    //
    // When this flag is not set and the profile is one of the above, WDF
    // creates a SGLookasideList used by this DMA adapter's transaction
    // objects. The SGLookasideList is initialized to allow the max specified
    // transfer length. When the transaction is executed, WDF calls the WDM
    // DMA's BuildScatterGatherList entry function. Forward progress drivers
    // must use this option. This is the default option.
    //
    // When this flag is set and the profile is one of the above, WDF
    // does not create a SGLookasideList. When the transaction is executed,
    // WDF calls the WDM DMA's GetScatterGatherList entry function.
    //
    WDF_DMA_ENABLER_CONFIG_NO_SGLIST_PREALLOCATION  = 0x00000001,

    //
    // This flag applies to all DMA profiles. When it is set, WDF will not
    // fragment any WDFDMATRANSACTION created with this enabler into multiple
    // DMA transfers. If this is not possible, initializing or executing the
    // transaction will fail. This option is intended for devices that need to
    // receive all data in a single DMA operation.
    //
    // Drivers also have the option of specifying this on a per-transaction
    // level with WdfDmaTransactionSetSingleTransferRequirement.
    //
    WDF_DMA_ENABLER_CONFIG_REQUIRE_SINGLE_TRANSFER  = 0x00000002,
} WDF_DMA_ENABLER_CONFIG_FLAGS;


typedef struct _WDF_DMA_ENABLER_CONFIG {
    //
    // Size of this structure in bytes
    //
    ULONG                Size;

    //
    // One of the above WDF_DMA_PROFILES
    //
    WDF_DMA_PROFILE      Profile;

    //
    // Maximum DMA Transfer handled in bytes.
    //
    size_t               MaximumLength;

    //
    // The various DMA PnP/Power event callbacks
    //
    PFN_WDF_DMA_ENABLER_FILL                  EvtDmaEnablerFill;
    PFN_WDF_DMA_ENABLER_FLUSH                 EvtDmaEnablerFlush;
    PFN_WDF_DMA_ENABLER_DISABLE               EvtDmaEnablerDisable;
    PFN_WDF_DMA_ENABLER_ENABLE                EvtDmaEnablerEnable;
    PFN_WDF_DMA_ENABLER_SELFMANAGED_IO_START  EvtDmaEnablerSelfManagedIoStart;
    PFN_WDF_DMA_ENABLER_SELFMANAGED_IO_STOP   EvtDmaEnablerSelfManagedIoStop;

    //
    // Overrides the address width specified by the DMA profile.
    //
    ULONG               AddressWidthOverride;

    //
    // Overrides the version of the WDM DMA interfaces that WDF uses
    // (0 for default).
    //
    ULONG               WdmDmaVersionOverride;

    //
    // Bit field combination of values from the WDF_DMA_ENABLER_CONFIG_FLAGS
    // enumeration
    //
    ULONG               Flags;
} WDF_DMA_ENABLER_CONFIG, *PWDF_DMA_ENABLER_CONFIG;

VOID
FORCEINLINE
WDF_DMA_ENABLER_CONFIG_INIT(
    _Out_ PWDF_DMA_ENABLER_CONFIG Config,
    _In_  WDF_DMA_PROFILE    Profile,
    _In_  size_t             MaximumLength
    )
{
    RtlZeroMemory(Config, sizeof(WDF_DMA_ENABLER_CONFIG));

    Config->Size = WDF_STRUCTURE_SIZE(WDF_DMA_ENABLER_CONFIG);
    Config->Profile = Profile;
    Config->MaximumLength = MaximumLength;
}

typedef struct _WDF_DMA_SYSTEM_PROFILE_CONFIG {

    //
    // The size of this structure in bytes
    //
    ULONG                 Size;

    //
    // Specifies that the transfer is controlled by the device's DMA
    // request line.
    //

    BOOLEAN               DemandMode;

    //
    // Specifies that the DMA engine will loop back to the beginning
    // of the buffer once it reaches the end.
    //

    BOOLEAN               LoopedTransfer;

    //
    // Width of the register to DMA to/from
    //

    DMA_WIDTH             DmaWidth;

    //
    // The adress at which to write to the device
    //
    PHYSICAL_ADDRESS      DeviceAddress;

    //
    // The translated resource descriptor for the DMA channel assigned
    // the device during EvtDevicePrepareHardware
    //
    PCM_PARTIAL_RESOURCE_DESCRIPTOR DmaDescriptor;

} WDF_DMA_SYSTEM_PROFILE_CONFIG, *PWDF_DMA_SYSTEM_PROFILE_CONFIG;

VOID
FORCEINLINE
WDF_DMA_SYSTEM_PROFILE_CONFIG_INIT(
    _Out_ PWDF_DMA_SYSTEM_PROFILE_CONFIG  DmaConfig,
    _In_  PHYSICAL_ADDRESS                Address,
    _In_  DMA_WIDTH                       DmaWidth,
    _In_  PCM_PARTIAL_RESOURCE_DESCRIPTOR DmaDescriptor
    )
{
    RtlZeroMemory(DmaConfig, sizeof(WDF_DMA_SYSTEM_PROFILE_CONFIG));

    DmaConfig->Size = WDF_STRUCTURE_SIZE(WDF_DMA_SYSTEM_PROFILE_CONFIG);
    DmaConfig->DeviceAddress = Address;
    DmaConfig->DmaWidth = DmaWidth;
    DmaConfig->DmaDescriptor = DmaDescriptor;
}

//
// WDF Function: WdfDmaEnablerCreate
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_WDFDMAENABLERCREATE)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDEVICE Device,
    _In_
    PWDF_DMA_ENABLER_CONFIG Config,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _Out_
    WDFDMAENABLER* DmaEnablerHandle
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
WdfDmaEnablerCreate(
    _In_
    WDFDEVICE Device,
    _In_
    PWDF_DMA_ENABLER_CONFIG Config,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _Out_
    WDFDMAENABLER* DmaEnablerHandle
    )
{
    return ((PFN_WDFDMAENABLERCREATE) WdfFunctions[WdfDmaEnablerCreateTableIndex])(WdfDriverGlobals, Device, Config, Attributes, DmaEnablerHandle);
}

//
// WDF Function: WdfDmaEnablerConfigureSystemProfile
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_WDFDMAENABLERCONFIGURESYSTEMPROFILE)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDMAENABLER DmaEnabler,
    _In_
    PWDF_DMA_SYSTEM_PROFILE_CONFIG ProfileConfig,
    _In_
    WDF_DMA_DIRECTION ConfigDirection
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
WdfDmaEnablerConfigureSystemProfile(
    _In_
    WDFDMAENABLER DmaEnabler,
    _In_
    PWDF_DMA_SYSTEM_PROFILE_CONFIG ProfileConfig,
    _In_
    WDF_DMA_DIRECTION ConfigDirection
    )
{
    return ((PFN_WDFDMAENABLERCONFIGURESYSTEMPROFILE) WdfFunctions[WdfDmaEnablerConfigureSystemProfileTableIndex])(WdfDriverGlobals, DmaEnabler, ProfileConfig, ConfigDirection);
}

//
// WDF Function: WdfDmaEnablerGetMaximumLength
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
size_t
(NTAPI *PFN_WDFDMAENABLERGETMAXIMUMLENGTH)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDMAENABLER DmaEnabler
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
size_t
WdfDmaEnablerGetMaximumLength(
    _In_
    WDFDMAENABLER DmaEnabler
    )
{
    return ((PFN_WDFDMAENABLERGETMAXIMUMLENGTH) WdfFunctions[WdfDmaEnablerGetMaximumLengthTableIndex])(WdfDriverGlobals, DmaEnabler);
}

//
// WDF Function: WdfDmaEnablerGetMaximumScatterGatherElements
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
size_t
(NTAPI *PFN_WDFDMAENABLERGETMAXIMUMSCATTERGATHERELEMENTS)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDMAENABLER DmaEnabler
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
size_t
WdfDmaEnablerGetMaximumScatterGatherElements(
    _In_
    WDFDMAENABLER DmaEnabler
    )
{
    return ((PFN_WDFDMAENABLERGETMAXIMUMSCATTERGATHERELEMENTS) WdfFunctions[WdfDmaEnablerGetMaximumScatterGatherElementsTableIndex])(WdfDriverGlobals, DmaEnabler);
}

//
// WDF Function: WdfDmaEnablerSetMaximumScatterGatherElements
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
VOID
(NTAPI *PFN_WDFDMAENABLERSETMAXIMUMSCATTERGATHERELEMENTS)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDMAENABLER DmaEnabler,
    _In_
    _When_(MaximumFragments == 0, __drv_reportError(MaximumFragments cannot be zero))
    size_t MaximumFragments
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
VOID
WdfDmaEnablerSetMaximumScatterGatherElements(
    _In_
    WDFDMAENABLER DmaEnabler,
    _In_
    _When_(MaximumFragments == 0, __drv_reportError(MaximumFragments cannot be zero))
    size_t MaximumFragments
    )
{
    ((PFN_WDFDMAENABLERSETMAXIMUMSCATTERGATHERELEMENTS) WdfFunctions[WdfDmaEnablerSetMaximumScatterGatherElementsTableIndex])(WdfDriverGlobals, DmaEnabler, MaximumFragments);
}

//
// WDF Function: WdfDmaEnablerGetFragmentLength
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
size_t
(NTAPI *PFN_WDFDMAENABLERGETFRAGMENTLENGTH)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDMAENABLER DmaEnabler,
    _In_
    WDF_DMA_DIRECTION DmaDirection
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
size_t
WdfDmaEnablerGetFragmentLength(
    _In_
    WDFDMAENABLER DmaEnabler,
    _In_
    WDF_DMA_DIRECTION DmaDirection
    )
{
    return ((PFN_WDFDMAENABLERGETFRAGMENTLENGTH) WdfFunctions[WdfDmaEnablerGetFragmentLengthTableIndex])(WdfDriverGlobals, DmaEnabler, DmaDirection);
}

//
// WDF Function: WdfDmaEnablerWdmGetDmaAdapter
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
PDMA_ADAPTER
(NTAPI *PFN_WDFDMAENABLERWDMGETDMAADAPTER)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDMAENABLER DmaEnabler,
    _In_
    WDF_DMA_DIRECTION DmaDirection
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
PDMA_ADAPTER
WdfDmaEnablerWdmGetDmaAdapter(
    _In_
    WDFDMAENABLER DmaEnabler,
    _In_
    WDF_DMA_DIRECTION DmaDirection
    )
{
    return ((PFN_WDFDMAENABLERWDMGETDMAADAPTER) WdfFunctions[WdfDmaEnablerWdmGetDmaAdapterTableIndex])(WdfDriverGlobals, DmaEnabler, DmaDirection);
}



#endif // (NTDDI_VERSION >= NTDDI_WIN2K)


WDF_EXTERN_C_END

#endif // _WDFDMAENABLER_H_

