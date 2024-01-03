window.onload = () => {
  const fileInput = document.getElementById("fileInput");
  fileInput.addEventListener("change", handleFileSelect, false);
};

function handleFileSelect(event) {
  const file = event.target.files[0];
  if (!file) {
    return;
  }

  const reader = new FileReader();
  reader.onload = (e) => {
    const content = e.target.result;
    const data = parseData(content);
    displayDataOnMap(data);
  };
  reader.readAsText(file);
}

function parseData(content) {
  const lines = content.split("\n");
  return lines
    .map((line) => {
      try {
        // Extract the JSON part of the line
        const jsonPart = line.match(/{.*}/);
        if (!jsonPart) throw new Error("No JSON found");

        // Parse the JSON part
        const parsedLine = JSON.parse(jsonPart[0]);

        // Extract RSSI if it's part of the line
        const rssiMatch = line.match(/RSSI\s*([-\d]+)/);
        if (rssiMatch && rssiMatch[1]) {
          parsedLine.RSSI = parseInt(rssiMatch[1], 10);
        }

        return {
            ...parsedLine,
            lng: parsedLine.lon,
        };
      } catch (e) {
        console.warn("Invalid JSON:", line, e.message);
        return null;
      }
    })
    .filter((entry) => entry !== null);
}



function renderChart(data) {
  const chartData = data.map(entry => ({
    x: entry.timestamp, // Use timestamp or another suitable property
    y: entry.RSSI,
  }));

  const options = {
    chart: {
      type: 'line',
    },
    series: [
      {
        name: 'RSSI Data',
        data: chartData,
      },
    ],
    xaxis: {
      type: 'datetime', // Use 'datetime' if timestamp is used as x-axis
    },
  };

  const chart = new ApexCharts(document.querySelector('#chart'), options);
  chart.render();
}
function determineColor(RSSI) {
  // Implement your logic to determine color based on RSSI value
  // For example:
  if (RSSI > -50) return "#00ff00"; // Strong signal
  else if (RSSI > -70) return "#ffff00"; // Medium signal
  else return "#ff0000"; // Weak signal
}
