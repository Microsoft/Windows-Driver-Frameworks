/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

_WdfVersionBuild_

Module Name:

    wdfresource.h

Abstract:

    This defines the DDIs for hardware resources

Environment:

    kernel mode only

Revision History:

--*/

//
// NOTE: This header is generated by stubwork.  Please make any 
//       modifications to the corresponding template files 
//       (.x or .y) and use stubwork to regenerate the header
//

#ifndef _WDFRESOURCE_H_
#define _WDFRESOURCE_H_

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

#define WDF_INSERT_AT_END ((ULONG) -1)



//
// WDF Function: WdfIoResourceRequirementsListSetSlotNumber
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
VOID
(NTAPI *PFN_WDFIORESOURCEREQUIREMENTSLISTSETSLOTNUMBER)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFIORESREQLIST RequirementsList,
    _In_
    ULONG SlotNumber
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
VOID
WdfIoResourceRequirementsListSetSlotNumber(
    _In_
    WDFIORESREQLIST RequirementsList,
    _In_
    ULONG SlotNumber
    )
{
    ((PFN_WDFIORESOURCEREQUIREMENTSLISTSETSLOTNUMBER) WdfFunctions[WdfIoResourceRequirementsListSetSlotNumberTableIndex])(WdfDriverGlobals, RequirementsList, SlotNumber);
}

//
// WDF Function: WdfIoResourceRequirementsListSetInterfaceType
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
VOID
(NTAPI *PFN_WDFIORESOURCEREQUIREMENTSLISTSETINTERFACETYPE)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFIORESREQLIST RequirementsList,
    _In_
    _Strict_type_match_
    INTERFACE_TYPE InterfaceType
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
VOID
WdfIoResourceRequirementsListSetInterfaceType(
    _In_
    WDFIORESREQLIST RequirementsList,
    _In_
    _Strict_type_match_
    INTERFACE_TYPE InterfaceType
    )
{
    ((PFN_WDFIORESOURCEREQUIREMENTSLISTSETINTERFACETYPE) WdfFunctions[WdfIoResourceRequirementsListSetInterfaceTypeTableIndex])(WdfDriverGlobals, RequirementsList, InterfaceType);
}

//
// WDF Function: WdfIoResourceRequirementsListAppendIoResList
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_WDFIORESOURCEREQUIREMENTSLISTAPPENDIORESLIST)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFIORESREQLIST RequirementsList,
    _In_
    WDFIORESLIST IoResList
    );

_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
NTSTATUS
WdfIoResourceRequirementsListAppendIoResList(
    _In_
    WDFIORESREQLIST RequirementsList,
    _In_
    WDFIORESLIST IoResList
    )
{
    return ((PFN_WDFIORESOURCEREQUIREMENTSLISTAPPENDIORESLIST) WdfFunctions[WdfIoResourceRequirementsListAppendIoResListTableIndex])(WdfDriverGlobals, RequirementsList, IoResList);
}

//
// WDF Function: WdfIoResourceRequirementsListInsertIoResList
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_WDFIORESOURCEREQUIREMENTSLISTINSERTIORESLIST)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFIORESREQLIST RequirementsList,
    _In_
    WDFIORESLIST IoResList,
    _In_
    ULONG Index
    );

_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
NTSTATUS
WdfIoResourceRequirementsListInsertIoResList(
    _In_
    WDFIORESREQLIST RequirementsList,
    _In_
    WDFIORESLIST IoResList,
    _In_
    ULONG Index
    )
{
    return ((PFN_WDFIORESOURCEREQUIREMENTSLISTINSERTIORESLIST) WdfFunctions[WdfIoResourceRequirementsListInsertIoResListTableIndex])(WdfDriverGlobals, RequirementsList, IoResList, Index);
}

//
// WDF Function: WdfIoResourceRequirementsListGetCount
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
ULONG
(NTAPI *PFN_WDFIORESOURCEREQUIREMENTSLISTGETCOUNT)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFIORESREQLIST RequirementsList
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
ULONG
WdfIoResourceRequirementsListGetCount(
    _In_
    WDFIORESREQLIST RequirementsList
    )
{
    return ((PFN_WDFIORESOURCEREQUIREMENTSLISTGETCOUNT) WdfFunctions[WdfIoResourceRequirementsListGetCountTableIndex])(WdfDriverGlobals, RequirementsList);
}

//
// WDF Function: WdfIoResourceRequirementsListGetIoResList
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
WDFIORESLIST
(NTAPI *PFN_WDFIORESOURCEREQUIREMENTSLISTGETIORESLIST)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFIORESREQLIST RequirementsList,
    _In_
    ULONG Index
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
WDFIORESLIST
WdfIoResourceRequirementsListGetIoResList(
    _In_
    WDFIORESREQLIST RequirementsList,
    _In_
    ULONG Index
    )
{
    return ((PFN_WDFIORESOURCEREQUIREMENTSLISTGETIORESLIST) WdfFunctions[WdfIoResourceRequirementsListGetIoResListTableIndex])(WdfDriverGlobals, RequirementsList, Index);
}

//
// WDF Function: WdfIoResourceRequirementsListRemove
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
VOID
(NTAPI *PFN_WDFIORESOURCEREQUIREMENTSLISTREMOVE)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFIORESREQLIST RequirementsList,
    _In_
    ULONG Index
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
VOID
WdfIoResourceRequirementsListRemove(
    _In_
    WDFIORESREQLIST RequirementsList,
    _In_
    ULONG Index
    )
{
    ((PFN_WDFIORESOURCEREQUIREMENTSLISTREMOVE) WdfFunctions[WdfIoResourceRequirementsListRemoveTableIndex])(WdfDriverGlobals, RequirementsList, Index);
}

//
// WDF Function: WdfIoResourceRequirementsListRemoveByIoResList
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
VOID
(NTAPI *PFN_WDFIORESOURCEREQUIREMENTSLISTREMOVEBYIORESLIST)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFIORESREQLIST RequirementsList,
    _In_
    WDFIORESLIST IoResList
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
VOID
WdfIoResourceRequirementsListRemoveByIoResList(
    _In_
    WDFIORESREQLIST RequirementsList,
    _In_
    WDFIORESLIST IoResList
    )
{
    ((PFN_WDFIORESOURCEREQUIREMENTSLISTREMOVEBYIORESLIST) WdfFunctions[WdfIoResourceRequirementsListRemoveByIoResListTableIndex])(WdfDriverGlobals, RequirementsList, IoResList);
}

//
// WDF Function: WdfIoResourceListCreate
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_WDFIORESOURCELISTCREATE)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFIORESREQLIST RequirementsList,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _Out_
    WDFIORESLIST* ResourceList
    );

_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
NTSTATUS
WdfIoResourceListCreate(
    _In_
    WDFIORESREQLIST RequirementsList,
    _In_opt_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _Out_
    WDFIORESLIST* ResourceList
    )
{
    return ((PFN_WDFIORESOURCELISTCREATE) WdfFunctions[WdfIoResourceListCreateTableIndex])(WdfDriverGlobals, RequirementsList, Attributes, ResourceList);
}

//
// WDF Function: WdfIoResourceListAppendDescriptor
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_WDFIORESOURCELISTAPPENDDESCRIPTOR)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFIORESLIST ResourceList,
    _In_
    PIO_RESOURCE_DESCRIPTOR Descriptor
    );

_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
NTSTATUS
WdfIoResourceListAppendDescriptor(
    _In_
    WDFIORESLIST ResourceList,
    _In_
    PIO_RESOURCE_DESCRIPTOR Descriptor
    )
{
    return ((PFN_WDFIORESOURCELISTAPPENDDESCRIPTOR) WdfFunctions[WdfIoResourceListAppendDescriptorTableIndex])(WdfDriverGlobals, ResourceList, Descriptor);
}

//
// WDF Function: WdfIoResourceListInsertDescriptor
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_WDFIORESOURCELISTINSERTDESCRIPTOR)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFIORESLIST ResourceList,
    _In_
    PIO_RESOURCE_DESCRIPTOR Descriptor,
    _In_
    ULONG Index
    );

_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
NTSTATUS
WdfIoResourceListInsertDescriptor(
    _In_
    WDFIORESLIST ResourceList,
    _In_
    PIO_RESOURCE_DESCRIPTOR Descriptor,
    _In_
    ULONG Index
    )
{
    return ((PFN_WDFIORESOURCELISTINSERTDESCRIPTOR) WdfFunctions[WdfIoResourceListInsertDescriptorTableIndex])(WdfDriverGlobals, ResourceList, Descriptor, Index);
}

//
// WDF Function: WdfIoResourceListUpdateDescriptor
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
VOID
(NTAPI *PFN_WDFIORESOURCELISTUPDATEDESCRIPTOR)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFIORESLIST ResourceList,
    _In_
    PIO_RESOURCE_DESCRIPTOR Descriptor,
    _In_
    ULONG Index
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
VOID
WdfIoResourceListUpdateDescriptor(
    _In_
    WDFIORESLIST ResourceList,
    _In_
    PIO_RESOURCE_DESCRIPTOR Descriptor,
    _In_
    ULONG Index
    )
{
    ((PFN_WDFIORESOURCELISTUPDATEDESCRIPTOR) WdfFunctions[WdfIoResourceListUpdateDescriptorTableIndex])(WdfDriverGlobals, ResourceList, Descriptor, Index);
}

//
// WDF Function: WdfIoResourceListGetCount
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
ULONG
(NTAPI *PFN_WDFIORESOURCELISTGETCOUNT)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFIORESLIST ResourceList
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
ULONG
WdfIoResourceListGetCount(
    _In_
    WDFIORESLIST ResourceList
    )
{
    return ((PFN_WDFIORESOURCELISTGETCOUNT) WdfFunctions[WdfIoResourceListGetCountTableIndex])(WdfDriverGlobals, ResourceList);
}

//
// WDF Function: WdfIoResourceListGetDescriptor
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
PIO_RESOURCE_DESCRIPTOR
(NTAPI *PFN_WDFIORESOURCELISTGETDESCRIPTOR)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFIORESLIST ResourceList,
    _In_
    ULONG Index
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
PIO_RESOURCE_DESCRIPTOR
WdfIoResourceListGetDescriptor(
    _In_
    WDFIORESLIST ResourceList,
    _In_
    ULONG Index
    )
{
    return ((PFN_WDFIORESOURCELISTGETDESCRIPTOR) WdfFunctions[WdfIoResourceListGetDescriptorTableIndex])(WdfDriverGlobals, ResourceList, Index);
}

//
// WDF Function: WdfIoResourceListRemove
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
VOID
(NTAPI *PFN_WDFIORESOURCELISTREMOVE)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFIORESLIST ResourceList,
    _In_
    ULONG Index
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
VOID
WdfIoResourceListRemove(
    _In_
    WDFIORESLIST ResourceList,
    _In_
    ULONG Index
    )
{
    ((PFN_WDFIORESOURCELISTREMOVE) WdfFunctions[WdfIoResourceListRemoveTableIndex])(WdfDriverGlobals, ResourceList, Index);
}

//
// WDF Function: WdfIoResourceListRemoveByDescriptor
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
VOID
(NTAPI *PFN_WDFIORESOURCELISTREMOVEBYDESCRIPTOR)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFIORESLIST ResourceList,
    _In_
    PIO_RESOURCE_DESCRIPTOR Descriptor
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
VOID
WdfIoResourceListRemoveByDescriptor(
    _In_
    WDFIORESLIST ResourceList,
    _In_
    PIO_RESOURCE_DESCRIPTOR Descriptor
    )
{
    ((PFN_WDFIORESOURCELISTREMOVEBYDESCRIPTOR) WdfFunctions[WdfIoResourceListRemoveByDescriptorTableIndex])(WdfDriverGlobals, ResourceList, Descriptor);
}

//
// WDF Function: WdfCmResourceListAppendDescriptor
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_WDFCMRESOURCELISTAPPENDDESCRIPTOR)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFCMRESLIST List,
    _In_
    PCM_PARTIAL_RESOURCE_DESCRIPTOR Descriptor
    );

_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
NTSTATUS
WdfCmResourceListAppendDescriptor(
    _In_
    WDFCMRESLIST List,
    _In_
    PCM_PARTIAL_RESOURCE_DESCRIPTOR Descriptor
    )
{
    return ((PFN_WDFCMRESOURCELISTAPPENDDESCRIPTOR) WdfFunctions[WdfCmResourceListAppendDescriptorTableIndex])(WdfDriverGlobals, List, Descriptor);
}

//
// WDF Function: WdfCmResourceListInsertDescriptor
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_WDFCMRESOURCELISTINSERTDESCRIPTOR)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFCMRESLIST List,
    _In_
    PCM_PARTIAL_RESOURCE_DESCRIPTOR Descriptor,
    _In_
    ULONG Index
    );

_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
NTSTATUS
WdfCmResourceListInsertDescriptor(
    _In_
    WDFCMRESLIST List,
    _In_
    PCM_PARTIAL_RESOURCE_DESCRIPTOR Descriptor,
    _In_
    ULONG Index
    )
{
    return ((PFN_WDFCMRESOURCELISTINSERTDESCRIPTOR) WdfFunctions[WdfCmResourceListInsertDescriptorTableIndex])(WdfDriverGlobals, List, Descriptor, Index);
}

//
// WDF Function: WdfCmResourceListGetCount
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
ULONG
(NTAPI *PFN_WDFCMRESOURCELISTGETCOUNT)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFCMRESLIST List
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
ULONG
WdfCmResourceListGetCount(
    _In_
    WDFCMRESLIST List
    )
{
    return ((PFN_WDFCMRESOURCELISTGETCOUNT) WdfFunctions[WdfCmResourceListGetCountTableIndex])(WdfDriverGlobals, List);
}

//
// WDF Function: WdfCmResourceListGetDescriptor
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
PCM_PARTIAL_RESOURCE_DESCRIPTOR
(NTAPI *PFN_WDFCMRESOURCELISTGETDESCRIPTOR)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFCMRESLIST List,
    _In_
    ULONG Index
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
PCM_PARTIAL_RESOURCE_DESCRIPTOR
WdfCmResourceListGetDescriptor(
    _In_
    WDFCMRESLIST List,
    _In_
    ULONG Index
    )
{
    return ((PFN_WDFCMRESOURCELISTGETDESCRIPTOR) WdfFunctions[WdfCmResourceListGetDescriptorTableIndex])(WdfDriverGlobals, List, Index);
}

//
// WDF Function: WdfCmResourceListRemove
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
VOID
(NTAPI *PFN_WDFCMRESOURCELISTREMOVE)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFCMRESLIST List,
    _In_
    ULONG Index
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
VOID
WdfCmResourceListRemove(
    _In_
    WDFCMRESLIST List,
    _In_
    ULONG Index
    )
{
    ((PFN_WDFCMRESOURCELISTREMOVE) WdfFunctions[WdfCmResourceListRemoveTableIndex])(WdfDriverGlobals, List, Index);
}

//
// WDF Function: WdfCmResourceListRemoveByDescriptor
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
VOID
(NTAPI *PFN_WDFCMRESOURCELISTREMOVEBYDESCRIPTOR)(
    _In_
    PWDF_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFCMRESLIST List,
    _In_
    PCM_PARTIAL_RESOURCE_DESCRIPTOR Descriptor
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
VOID
WdfCmResourceListRemoveByDescriptor(
    _In_
    WDFCMRESLIST List,
    _In_
    PCM_PARTIAL_RESOURCE_DESCRIPTOR Descriptor
    )
{
    ((PFN_WDFCMRESOURCELISTREMOVEBYDESCRIPTOR) WdfFunctions[WdfCmResourceListRemoveByDescriptorTableIndex])(WdfDriverGlobals, List, Descriptor);
}



#endif // (NTDDI_VERSION >= NTDDI_WIN2K)


WDF_EXTERN_C_END

#endif // _WDFRESOURCE_H_

