#pragma once

#include "Blueprint/UserWidget.h"
#include "QDOS_Types/QDOS_Types.h"
#include "Order_Menu_Widget.generated.h"

class UComboBoxString;
class UButton;
class UCheckBox;

// UOrder_Menu_Widget
//------------------------------------------------------------------------------------------------------------
UCLASS(Abstract) class QDOS_API UOrder_Menu_Widget: public UUserWidget
{
	GENERATED_BODY()
	
public:
	UOrder_Menu_Widget(const FObjectInitializer& obj_initializer);
	void Set_View_Model(UVM_Drink_Order *vm_drink_order);
	
protected:
	virtual void NativeConstruct() override;
	
	UPROPERTY(BlueprintReadWrite, Meta = (BindWidget) ) UComboBoxString *Drinks_Combo_Box = 0;
	UPROPERTY(BlueprintReadWrite, Meta = (BindWidget) ) UCheckBox *Add_Milk_Check_Box = 0;
	UPROPERTY(BlueprintReadWrite, Meta = (BindWidget) ) UCheckBox *Add_Sugar_Check_Box = 0;
	UPROPERTY(BlueprintReadWrite, Meta = (BindWidget) ) UButton *Place_Order_Button = 0;
	UPROPERTY(BlueprintReadWrite, Meta = (BindWidget) ) UButton *Back_Button = 0;
	UPROPERTY(BlueprintAssignable) FOn_View_Model_Updated On_View_Model_Updated;
		
private:
	UFUNCTION() void On_Drink_Changed(FString selected_item, ESelectInfo::Type selection_type);
	UFUNCTION() void On_Place_Order();
	UFUNCTION() void On_Back_Button_Clicked();
	
	UVM_Drink_Order *VM_Drink_Order = 0;
};
//------------------------------------------------------------------------------------------------------------
