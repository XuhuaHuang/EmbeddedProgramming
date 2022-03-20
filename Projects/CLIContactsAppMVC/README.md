# MVC
## Definition
### Model
* Handles data and logic
* Interacts with database

### View
* Handles data presentation
* Dynamically rendered (AJAX)

### Controller
* Handles request flow
* Never handles data and logic

## Control Flow
1. Request - User to Controller
2. Get data - Controller to Model
3. Get presentation - Controller to View

**Note that Model never interacts with View; it's done by controller**  
**Separates the calculations and interface from each other**
