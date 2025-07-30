#include "VM_Drink_Order.h"

// UDrink_Order_View_Model
//------------------------------------------------------------------------------------------------------------
void UVM_Drink_Order::Full_Update()
{
	UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(Get_Order_Summary);
}
//------------------------------------------------------------------------------------------------------------
FText UVM_Drink_Order::Get_Order_Summary() const
{
	FString order_summary;
	FString supplements;
	FString with_milk;
	FString with_sugar;
	
	with_milk = TEXT("с молоком");
	with_sugar = TEXT("с сахаром");

	supplements = "";
	
	if (Add_Sugar_State == ECheckBoxState::Checked && Add_Milk_State == ECheckBoxState::Checked)
		supplements = FString::Printf(TEXT("%s и %s"), *with_milk, *with_sugar);  // With milk and sugar
	else
		if (Add_Sugar_State == ECheckBoxState::Unchecked && Add_Milk_State == ECheckBoxState::Checked)
			supplements = FString::Printf(TEXT("%s"), *with_milk);  // With milk only 
		else
			if (Add_Sugar_State == ECheckBoxState::Checked && Add_Milk_State == ECheckBoxState::Unchecked)
				supplements = FString::Printf(TEXT("%s"), *with_sugar);  // With sugar only
			
	order_summary = FString::Printf(TEXT("Вы заказали %s %s"), *Selected_Drink_Name, *supplements);

	return FText::FromString(order_summary);
}
//------------------------------------------------------------------------------------------------------------
void UVM_Drink_Order::Go_Back()
{
	check(Curr_Page_Index > 0);

	Set_Curr_Page_Index(Curr_Page_Index - 1);
}
//------------------------------------------------------------------------------------------------------------
void UVM_Drink_Order::Go_Forward()
{
	Set_Curr_Page_Index(Curr_Page_Index + 1);
}
//------------------------------------------------------------------------------------------------------------
void UVM_Drink_Order::Set_Curr_Page_Index(int32 new_page_index)
{
	int32 new_page_index_clamped;
	
	new_page_index_clamped = new_page_index % 3;
	
	UE_MVVM_SET_PROPERTY_VALUE(Curr_Page_Index, new_page_index_clamped);

	On_Current_Page_Changed.Broadcast();
}
//------------------------------------------------------------------------------------------------------------
int32 UVM_Drink_Order::Get_Curr_Page_Index() const
{
	return Curr_Page_Index;
}
//------------------------------------------------------------------------------------------------------------
 void UVM_Drink_Order::Set_Selected_Drink_Name(FString new_selected_drink_name)
 {
 	UE_MVVM_SET_PROPERTY_VALUE(Selected_Drink_Name, new_selected_drink_name);
 }
 //------------------------------------------------------------------------------------------------------------
 FString UVM_Drink_Order::Get_Selected_Drink_Name() const
 {
 	return Selected_Drink_Name;
 }
 //------------------------------------------------------------------------------------------------------------
 void UVM_Drink_Order::Set_Add_Sugar_State(ECheckBoxState new_add_sugar_state)
 {
 	UE_MVVM_SET_PROPERTY_VALUE(Add_Sugar_State, new_add_sugar_state);
 }
 //------------------------------------------------------------------------------------------------------------
 ECheckBoxState UVM_Drink_Order::Get_Add_Sugar_State() const
 {
 	return Add_Sugar_State;
 }
 //------------------------------------------------------------------------------------------------------------
 void UVM_Drink_Order::Set_Add_Milk_State(ECheckBoxState new_add_milk_state)
 {
 	UE_MVVM_SET_PROPERTY_VALUE(Add_Milk_State, new_add_milk_state);
 }
 //------------------------------------------------------------------------------------------------------------
 ECheckBoxState UVM_Drink_Order::Get_Add_Milk_State() const
 {
 	return Add_Milk_State;
 }
 //------------------------------------------------------------------------------------------------------------
