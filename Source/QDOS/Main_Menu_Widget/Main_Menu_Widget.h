#pragma once

#include "Blueprint/UserWidget.h"
#include "QDOS_Types/QDOS_Types.h"
#include "Main_Menu_Widget.generated.h"

class UOrder_Menu_Widget;
class UConfirmation_Widget;
class UWidgetSwitcher;
class UButton;
class UVM_Drink_Order;

// UMain_Menu_Widget
//------------------------------------------------------------------------------------------------------------
UCLASS(Abstract) class QDOS_API UMain_Menu_Widget: public UUserWidget
{
	GENERATED_BODY()

public:
	UMain_Menu_Widget(const FObjectInitializer &ObjectInitializer);
	void Set_View_Model(UVM_Drink_Order *vm_drink_order);
	
protected:
	virtual void NativeConstruct() override;

	UPROPERTY(Meta = (BindWidget) ) UButton *Order_Menu_Button = 0;
	UPROPERTY(Meta = (BindWidget) ) UButton *Leave_Game_Button = 0;
	UPROPERTY(BlueprintAssignable) FOn_View_Model_Updated On_View_Model_Updated;
	
private:
	UFUNCTION() void Leave_Game();
	UFUNCTION() void On_Order_Menu_Button_Clicked();
	UPROPERTY() UVM_Drink_Order *VM_Drink_Order = 0;
};
//------------------------------------------------------------------------------------------------------------
