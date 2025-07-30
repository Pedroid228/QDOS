#pragma once

#include "QDOS_Types.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOn_View_Model_Updated, UVM_Drink_Order*, view_model);

// EDrink_Type
//------------------------------------------------------------------------------------------------------------
UENUM() enum class EDrink_Type: uint8
{
	Tea UMETA(DisplayName = "чай"),
	Coffee UMETA(DisplayName = "кофе"),
	Juice UMETA(DisplayName = "сок")
};
//------------------------------------------------------------------------------------------------------------
