#include "Order_Menu_Widget.h"
#include "Components/Button.h"
#include "Components/CheckBox.h"
#include "Components/ComboBoxString.h"
#include "QDOS_Types/QDOS_Types.h"
#include "VM_Drink_Order/VM_Drink_Order.h"

// UOrder_Menu_Widget
//------------------------------------------------------------------------------------------------------------
UOrder_Menu_Widget::UOrder_Menu_Widget(const FObjectInitializer& obj_initializer)
: Super(obj_initializer)
{
}
//------------------------------------------------------------------------------------------------------------
void UOrder_Menu_Widget::Set_View_Model(UVM_Drink_Order *vm_drink_order)
{
	check(vm_drink_order != 0);
	On_View_Model_Updated.Broadcast(vm_drink_order);

	VM_Drink_Order = vm_drink_order;
}
//------------------------------------------------------------------------------------------------------------
void UOrder_Menu_Widget::NativeConstruct()
{
	FString curr_drink;
	UEnum *drinks_enum = 0;
	
	Super::NativeConstruct();

	check(Drinks_Combo_Box != 0);
	check(Add_Milk_Check_Box != 0);
	check(Add_Sugar_Check_Box != 0);
	check(Place_Order_Button != 0);
	check(Back_Button != 0);

	drinks_enum = StaticEnum<EDrink_Type>();
	for (int32 i = 0; i < drinks_enum->NumEnums() - 1; i++)
	{
		curr_drink = drinks_enum->GetDisplayNameTextByIndex(i).ToString();
		Drinks_Combo_Box->AddOption(curr_drink);

		if (i == 0)
		{
			Drinks_Combo_Box->SetSelectedOption(curr_drink);
			VM_Drink_Order->Set_Selected_Drink_Name(curr_drink);
		}
	}

	Drinks_Combo_Box->OnSelectionChanged.AddDynamic(this, &UOrder_Menu_Widget::On_Drink_Changed);
	Place_Order_Button->OnClicked.AddDynamic(this, &UOrder_Menu_Widget::On_Place_Order);
	Back_Button->OnClicked.AddDynamic(this, &UOrder_Menu_Widget::On_Back_Button_Clicked);
}
//------------------------------------------------------------------------------------------------------------
void UOrder_Menu_Widget::On_Drink_Changed(FString selected_item, ESelectInfo::Type selection_type)
{
	VM_Drink_Order->Set_Selected_Drink_Name(selected_item);
}
//------------------------------------------------------------------------------------------------------------
void UOrder_Menu_Widget::On_Place_Order()
{
	check(VM_Drink_Order != 0);
	
	VM_Drink_Order->Full_Update();
	VM_Drink_Order->Go_Forward();
}
//------------------------------------------------------------------------------------------------------------
void UOrder_Menu_Widget::On_Back_Button_Clicked()
{
	check(VM_Drink_Order != 0);
	
	VM_Drink_Order->Go_Back();
}
//------------------------------------------------------------------------------------------------------------
