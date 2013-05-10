console.log("Trying to use dot notation on QObject...")

try {
  ex.hey = hey
  console.log("[SUCCESS]")
} catch (e) {
  console.error("[FAILURE] " + e.stack)

  console.error("Falling back to using Object.defineProperty on QObject...")
  try {
    Object.defineProperty(ex, "hey", {value: hey})
    console.log("[SUCCESS]")
  } catch (e) {
    console.error("[FAILURE] " + e.stack)
  }
} finally {
  console.log("")
}

console.log("Calling new property...")
try {
  ex.hey()
  console.log("[SUCCESS]")
} catch (e) {
  console.error("[FAILURE] " + e.stack)
} finally {
  console.log("")
}

console.log("[DONE]")

console.log("")

console.log("Trying callback with signal")
console.signal.connect(function () {
  try {
    console.log("Throwing and catching exception")
    throw "SIGSEV?!"
  } catch (e) {
  }
  console.log("[SUCCESS]")
})
console.signal.connect(function () {
  console.log("Throwing and *not* catching exception")
  throw "SIGSEV?!"
  console.log("[SUCCESS]")
})
console.emitSignal()

// private

function hey() {
  console.log("hey")
}
