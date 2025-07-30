#pragma once

#include "Blueprint/UserWidget.h"
#include "QDOS_Widget.generated.h"

class UMain_Menu_Widget;
class UOrder_Menu_Widget;
class UConfirmation_Widget;
class UWidgetSwitcher;
class UVM_Drink_Order;

DECLARE_LOG_CATEGORY_EXTERN(QDOS_Widget_Log, All, All)

// UQDOS_Widget
//------------------------------------------------------------------------------------------------------------
UCLASS(Abstract) class QDOS_API UQDOS_Widget: public UUserWidget
{
	GENERATED_BODY()

public:
	UQDOS_Widget(const FObjectInitializer &obj_initializer);
	
protected:
	virtual void NativeConstruct() override;

	UPROPERTY(EditDefaultsOnly) TSubclassOf<UMain_Menu_Widget> Main_Menu_Widget_BP_Class;
	UPROPERTY(EditDefaultsOnly) TSubclassOf<UOrder_Menu_Widget> Order_Menu_Widget_BP_Class;
	UPROPERTY(EditDefaultsOnly) TSubclassOf<UConfirmation_Widget> Confirmation_Widget_BP_Class;
	UPROPERTY(Meta = (BindWidget) ) UWidgetSwitcher *Widget_Switcher = 0;
	
private:
	UFUNCTION() void On_Current_Page_Changed();
	
	UPROPERTY() UMain_Menu_Widget *Main_Menu_Widget = 0;
	UPROPERTY() UOrder_Menu_Widget *Order_Menu_Widget = 0;
	UPROPERTY() UConfirmation_Widget *Confirmation_Widget = 0;
	UPROPERTY() UVM_Drink_Order *VM_Drink_Order = 0;
};
//------------------------------------------------------------------------------------------------------------

