#include "QDOS_Widget.h"
#include "Main_Menu_Widget/Main_Menu_Widget.h"
#include "Order_Menu_Widget/Order_Menu_Widget.h"
#include "Confirmation_Widget/Confirmation_Widget.h"
#include "Components/WidgetSwitcher.h"
#include "VM_Drink_Order/VM_Drink_Order.h"

DEFINE_LOG_CATEGORY(QDOS_Widget_Log)

// UQDOS_Widget
//------------------------------------------------------------------------------------------------------------
UQDOS_Widget::UQDOS_Widget(const FObjectInitializer &obj_initializer)
: Super(obj_initializer)
{
}
//------------------------------------------------------------------------------------------------------------
void UQDOS_Widget::NativeConstruct()
{
	UWorld *world = 0;
	
	Super::NativeConstruct();

	check(Widget_Switcher != 0);

	world = GetWorld();
	check(world != 0);

	VM_Drink_Order = NewObject<UVM_Drink_Order>(this);
	check(VM_Drink_Order != 0);
	VM_Drink_Order->On_Current_Page_Changed.AddDynamic(this, &UQDOS_Widget::On_Current_Page_Changed);
	
	// Create Widgets
	Main_Menu_Widget = CreateWidget<UMain_Menu_Widget>(world, Main_Menu_Widget_BP_Class);
	check(Main_Menu_Widget != 0);
	Main_Menu_Widget->Set_View_Model(VM_Drink_Order);
	
	Order_Menu_Widget = CreateWidget<UOrder_Menu_Widget>(world, Order_Menu_Widget_BP_Class);
	check(Order_Menu_Widget != 0);
	Order_Menu_Widget->Set_View_Model(VM_Drink_Order);

	Confirmation_Widget = CreateWidget<UConfirmation_Widget>(world, Confirmation_Widget_BP_Class);
	check(Confirmation_Widget != 0);
	Confirmation_Widget->Set_View_Model(VM_Drink_Order);

	// Add Widgets to switcher
	Widget_Switcher->AddChild(Main_Menu_Widget);
	Widget_Switcher->AddChild(Order_Menu_Widget);
	Widget_Switcher->AddChild(Confirmation_Widget);
	
	VM_Drink_Order->Set_Curr_Page_Index(0);
}
//------------------------------------------------------------------------------------------------------------
void UQDOS_Widget::On_Current_Page_Changed()
{
	check(VM_Drink_Order != 0);
	
	Widget_Switcher->SetActiveWidgetIndex(VM_Drink_Order->Get_Curr_Page_Index() );
}
//------------------------------------------------------------------------------------------------------------

