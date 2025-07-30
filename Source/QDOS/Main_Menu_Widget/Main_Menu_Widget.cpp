#include "Main_Menu_Widget.h"
#include "VM_Drink_Order/VM_Drink_Order.h"
#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"

// UMain_Menu_Widget
//------------------------------------------------------------------------------------------------------------
UMain_Menu_Widget::UMain_Menu_Widget(const FObjectInitializer &obj_initializer)
: Super(obj_initializer)
{
}
//------------------------------------------------------------------------------------------------------------
void UMain_Menu_Widget::Set_View_Model(UVM_Drink_Order* vm_drink_order)
{
	check(vm_drink_order != 0);
	On_View_Model_Updated.Broadcast(vm_drink_order);

	VM_Drink_Order = vm_drink_order;
}
//------------------------------------------------------------------------------------------------------------
void UMain_Menu_Widget::NativeConstruct()
{
	Super::NativeConstruct();

	check(Order_Menu_Button != 0);
	check(Leave_Game_Button != 0);
	
	Order_Menu_Button->OnClicked.AddDynamic(this, &UMain_Menu_Widget::On_Order_Menu_Button_Clicked);
	Leave_Game_Button->OnClicked.AddDynamic(this, &UMain_Menu_Widget::Leave_Game);
}
//------------------------------------------------------------------------------------------------------------
void UMain_Menu_Widget::Leave_Game()
{
	UWorld *world = 0;
	APlayerController *player_controller = 0;
	
	world = GetWorld();
	check(world != 0);

	player_controller = world->GetFirstPlayerController();
	check(player_controller != 0);
	
	UKismetSystemLibrary::QuitGame(world, player_controller, EQuitPreference::Quit,false);
}
//------------------------------------------------------------------------------------------------------------
void UMain_Menu_Widget::On_Order_Menu_Button_Clicked()
{
	check(VM_Drink_Order != 0);
	VM_Drink_Order->Go_Forward();
}
//------------------------------------------------------------------------------------------------------------
