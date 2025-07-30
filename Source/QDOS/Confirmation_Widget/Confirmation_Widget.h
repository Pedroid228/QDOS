#pragma once

#include "Blueprint/UserWidget.h"
#include "QDOS_Types/QDOS_Types.h"
#include "Confirmation_Widget.generated.h"

class UTextBlock;
class UButton;
class UVM_Drink_Order;

// UConfirmation_Widget
//------------------------------------------------------------------------------------------------------------
UCLASS() class QDOS_API UConfirmation_Widget: public UUserWidget
{
	GENERATED_BODY()

public:
	UConfirmation_Widget(const FObjectInitializer &obj_initializer);
	void Set_View_Model(UVM_Drink_Order *vm_drink_order);
	
protected:
	virtual void NativeConstruct() override;
	
	UPROPERTY(BlueprintReadWrite, Meta = (BindWidget) ) UTextBlock *Order_Text = 0;
	UPROPERTY(BlueprintReadWrite, Meta = (BindWidget) ) UButton *To_Main_Menu_Button = 0;
	UPROPERTY(BlueprintAssignable) FOn_View_Model_Updated On_View_Model_Updated;
	
private:
	UFUNCTION() void On_Main_Menu();
	
	UPROPERTY() UVM_Drink_Order *VM_Drink_Order = 0;
};
//------------------------------------------------------------------------------------------------------------
