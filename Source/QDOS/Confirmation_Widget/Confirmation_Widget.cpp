#include "Confirmation_Widget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "VM_Drink_Order/VM_Drink_Order.h"

// UConfirmation_Widget
//------------------------------------------------------------------------------------------------------------
UConfirmation_Widget::UConfirmation_Widget(const FObjectInitializer &obj_initializer)
: Super(obj_initializer)
{
}
//------------------------------------------------------------------------------------------------------------
void UConfirmation_Widget::Set_View_Model(UVM_Drink_Order *vm_drink_order)
{
	check(vm_drink_order != 0);
	On_View_Model_Updated.Broadcast(vm_drink_order);

	VM_Drink_Order = vm_drink_order;
}
//------------------------------------------------------------------------------------------------------------
void UConfirmation_Widget::NativeConstruct()
{
	Super::NativeConstruct();

	check(Order_Text != 0);
	check(To_Main_Menu_Button != 0);
	check(Back_Button != 0)
	
	To_Main_Menu_Button->OnClicked.AddDynamic(this, &UConfirmation_Widget::On_Main_Menu);
	Back_Button->OnClicked.AddDynamic(this, &UConfirmation_Widget::On_Back);
}
//------------------------------------------------------------------------------------------------------------
void UConfirmation_Widget::On_Main_Menu()
{
	check(VM_Drink_Order);

	VM_Drink_Order->Go_Forward();
}
//------------------------------------------------------------------------------------------------------------
void UConfirmation_Widget::On_Back()
{
	check(VM_Drink_Order != 0);
	VM_Drink_Order->Go_Back();
}
//------------------------------------------------------------------------------------------------------------
