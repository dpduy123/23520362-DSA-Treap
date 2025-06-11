using Northwind.Models;
using Northwind.Interfaces;
using Microsoft.AspNetCore.Mvc;

namespace Northwind.Controllers
{
    public class EmployeeController
    {
        [Route("api/Employee")]
        [ApiController]
        public class EmployeeControllers : ControllerBase
        {
            private readonly IEmployeeRepository _employeeRepository;  // Use interface for dependency injection

            public EmployeeControllers(IEmployeeRepository employeeRepository)  // Inject repository in constructor
            {
                _employeeRepository = employeeRepository;
            }

            //[HttpGet]
            //public IEnumerable<Employee> GetAllEmployees()
            //{
            //    return _employeeRepository.GetAllEmployees();
            //}

            //[HttpGet("{id}")]
            //public IActionResult GetEmployeeById(int id)
            //{
            //    var employee = _employeeRepository.GetEmployeeById(id);
            //    if (employee == null)
            //    {
            //        return NotFound();
            //    }
            //    return Ok(employee);
            //}

            // Insert a new employee
            //[HttpPost]
            //public IActionResult InsertEmployee([FromBody] Employee employee)
            //{
            //    if (!ModelState.IsValid)
            //    {
            //        return BadRequest(ModelState);
            //    }

            //    _employeeRepository.InsertEmployee(employee);
            //    return CreatedAtRoute("GetEmployeeById", new { id = employee.EmployeeId }, employee);
            //}

            //// Update an employee
            //[HttpPut("{id}")]
            //public IActionResult UpdateEmployee(int id, [FromBody] Employee employee)
            //{
            //    if (id != employee.EmployeeId)
            //    {
            //        return BadRequest();
            //    }

            //    if (!ModelState.IsValid)
            //    {
            //        return BadRequest(ModelState);
            //    }

            //    _employeeRepository.UpdateEmployee(employee);
            //    return NoContent();
            //}

            // Delete an employee
            [HttpDelete("{id}")]
            public IActionResult DeleteEmployee(int id)
            {
                var employee = _employeeRepository.GetEmployee(id);
                if (employee == null)
                {
                    return NotFound();  
                }

                _employeeRepository.DeleteEmployee(employee);  

                return NoContent();  
            }
        }
    }
}