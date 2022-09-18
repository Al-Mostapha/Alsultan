var builder = WebApplication.CreateBuilder(args);
var app = builder.Build();



app.MapGet("/weatherforecast", () =>
{
    return new {
        Test = "Elkaisar"
    };
});

app.Run();
