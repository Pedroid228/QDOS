#pragma once

#include "MVVMViewModelBase.h"
#include "QDOS_Types/QDOS_Types.h"
#include "Styling/SlateTypes.h"
#include "VM_Drink_Order.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOn_Current_Page_Changed);

// UVM_Drink_Order
//------------------------------------------------------------------------------------------------------------
UCLASS() class UVM_Drink_Order: public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	void Full_Update();
	UFUNCTION(BlueprintPure, FieldNotify) FText Get_Order_Summary() const;
	UFUNCTION() void Go_Back();
	UFUNCTION() void Go_Forward();
	void Set_Curr_Page_Index(int32 new_page_index);
	int32 Get_Curr_Page_Index() const;
	void Set_Selected_Drink_Name(FString new_selected_drink_name);
	FString Get_Selected_Drink_Name() const;
	void Set_Add_Sugar_State(ECheckBoxState new_add_sugar_state);
	ECheckBoxState Get_Add_Sugar_State() const;
	void Set_Add_Milk_State(ECheckBoxState new_add_milk_state);
	ECheckBoxState Get_Add_Milk_State() const;

	FOn_Current_Page_Changed On_Current_Page_Changed;
	
protected:
	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter="Set_Curr_Page_Index", Getter="Get_Curr_Page_Index") int32 Curr_Page_Index;
	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter="Set_Selected_Drink_Name", Getter="Get_Selected_Drink_Name") FString Selected_Drink_Name;
	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter="Set_Add_Sugar_State", Getter="Get_Add_Sugar_State") ECheckBoxState Add_Sugar_State;
	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter="Set_Add_Milk_State", Getter="Get_Add_Milk_State") ECheckBoxState Add_Milk_State;
};
//------------------------------------------------------------------------------------------------------------
